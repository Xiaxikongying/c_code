#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#define MAX_BUFF_SIZE 1024

// �����ص��ṹ��
typedef struct _PER_IO_OPERATION_DATA
{
    WSAOVERLAPPED Overlapped;
    WSABUF DataBuf;
    CHAR Buffer[MAX_BUFF_SIZE];
    DWORD BytesSend;
    DWORD BytesRecv;
} PER_IO_OPERATION_DATA, *LPPER_IO_OPERATION_DATA;

int main()
{
    // ��ʼ��Windows Socket��
    WSAData wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    // ����socket�����ͻ�������
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8888);
    // �󶨵�ַ�Ͷ˿�
    iResult = bind(listenSocket, (sockaddr *)&serverAddr, sizeof(serverAddr));
    // ��ʼ����
    iResult = listen(listenSocket, SOMAXCONN);

    // ����IOCP
    HANDLE iocpHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    // ������socket������IOCP��
    CreateIoCompletionPort((HANDLE)listenSocket, iocpHandle, 0, 0);

    while (true)
    {
        sockaddr_in clientAddr;
        int addrLen = sizeof(clientAddr);
        // ���տͻ�������
        SOCKET clientSocket = accept(listenSocket, (sockaddr *)&clientAddr, &addrLen);
        // ���ͻ���socket������IOCP��
        HANDLE clientHandle = CreateIoCompletionPort((HANDLE)clientSocket, iocpHandle, 0, 0);
        // �����ص��ṹ��
        LPPER_IO_OPERATION_DATA perIoData = new PER_IO_OPERATION_DATA();
        memset(&(perIoData->Overlapped), 0, sizeof(WSAOVERLAPPED));
        perIoData->DataBuf.len = MAX_BUFF_SIZE;
        perIoData->DataBuf.buf = perIoData->Buffer;

        DWORD bytesRecv = 0;
        DWORD flags = 0;

        // ���տͻ�������
        WSARecv(clientSocket, &(perIoData->DataBuf), 1, &bytesRecv, &flags, &(perIoData->Overlapped), NULL);
        std::cout << "Client connected: " << inet_ntoa(clientAddr.sin_addr) << ":" << ntohs(clientAddr.sin_port) << std::endl;
    }

    CloseHandle(iocpHandle);
    closesocket(listenSocket);
    WSACleanup();
    return 0;
}