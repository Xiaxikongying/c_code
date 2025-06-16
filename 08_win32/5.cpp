#include <winsock2.h>
#include <windows.h>
#include <mswsock.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080
#define MAX_THREADS 4
#define BUFFER_SIZE 1024

// ���ڴ洢 I/O �¼�����
struct IOData
{
    OVERLAPPED overlapped;  // OVERLAPPED �ṹ�������첽 I/O
    WSABUF buffer;          // �������ṹ
    char data[BUFFER_SIZE]; // ʵ�ʴ洢����
};

// ȫ�� I/O ��ɶ˿ھ��
HANDLE g_hIOCP;

// �̳߳ع����߳�
DWORD WINAPI WorkerThread(LPVOID lpParam)
{
    DWORD bytesTransferred;
    ULONG_PTR completionKey;
    IOData *pIOData;

    while (true)
    {
        BOOL result = GetQueuedCompletionStatus(
            g_hIOCP, &bytesTransferred, &completionKey, (LPOVERLAPPED *)&pIOData, INFINITE);

        if (!result || bytesTransferred == 0)
        {
            // ���ӹرջ�������
            closesocket(completionKey);
            delete pIOData;
            continue;
        }

        // ������յ������ݣ��򵥻��ԣ�
        printf("Received: %s\n", pIOData->data);
        send(completionKey, pIOData->data, bytesTransferred, 0);

        // �����첽����
        ZeroMemory(&pIOData->overlapped, sizeof(OVERLAPPED));
        DWORD flags = 0;
        WSARecv(completionKey, &pIOData->buffer, 1, NULL, &flags, &pIOData->overlapped, NULL);
    }
    return 0;
}

int main()
{
    // 1. ��ʼ�� Winsock
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 2. ���������׽���
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr = {0};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);
    bind(listenSocket, (sockaddr *)&serverAddr, sizeof(serverAddr));
    listen(listenSocket, SOMAXCONN);

    // 3. ���� I/O ��ɶ˿�
    g_hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);

    // 4. ���������̳߳�
    std::vector<HANDLE> threadHandles;
    for (int i = 0; i < MAX_THREADS; i++)
    {
        HANDLE hThread = CreateThread(NULL, 0, WorkerThread, NULL, 0, NULL);
        threadHandles.push_back(hThread);
    }

    printf("Server listening on port %d...\n", PORT);

    // 5. ���տͻ�������
    while (true)
    {
        SOCKET clientSocket = accept(listenSocket, NULL, NULL);
        if (clientSocket == INVALID_SOCKET)
            continue;

        // 6. �� clientSocket ������ IOCP
        CreateIoCompletionPort((HANDLE)clientSocket, g_hIOCP, (ULONG_PTR)clientSocket, 0);

        // 7. ���� IO ���ݽṹ����ʼ�첽����
        IOData *pIOData = new IOData();
        pIOData->buffer.buf = pIOData->data;
        pIOData->buffer.len = BUFFER_SIZE;

        ZeroMemory(&pIOData->overlapped, sizeof(OVERLAPPED));
        DWORD flags = 0;
        WSARecv(clientSocket, &pIOData->buffer, 1, NULL, &flags, &pIOData->overlapped, NULL);
    }

    // 8. �رշ�����
    WSACleanup();
    system("pause");
    return 0;
}
