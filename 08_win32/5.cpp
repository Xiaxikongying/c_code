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

// 用于存储 I/O 事件数据
struct IOData
{
    OVERLAPPED overlapped;  // OVERLAPPED 结构体用于异步 I/O
    WSABUF buffer;          // 缓冲区结构
    char data[BUFFER_SIZE]; // 实际存储数据
};

// 全局 I/O 完成端口句柄
HANDLE g_hIOCP;

// 线程池工作线程
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
            // 连接关闭或发生错误
            closesocket(completionKey);
            delete pIOData;
            continue;
        }

        // 处理接收到的数据（简单回显）
        printf("Received: %s\n", pIOData->data);
        send(completionKey, pIOData->data, bytesTransferred, 0);

        // 继续异步接收
        ZeroMemory(&pIOData->overlapped, sizeof(OVERLAPPED));
        DWORD flags = 0;
        WSARecv(completionKey, &pIOData->buffer, 1, NULL, &flags, &pIOData->overlapped, NULL);
    }
    return 0;
}

int main()
{
    // 1. 初始化 Winsock
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 2. 创建监听套接字
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr = {0};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);
    bind(listenSocket, (sockaddr *)&serverAddr, sizeof(serverAddr));
    listen(listenSocket, SOMAXCONN);

    // 3. 创建 I/O 完成端口
    g_hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);

    // 4. 创建工作线程池
    std::vector<HANDLE> threadHandles;
    for (int i = 0; i < MAX_THREADS; i++)
    {
        HANDLE hThread = CreateThread(NULL, 0, WorkerThread, NULL, 0, NULL);
        threadHandles.push_back(hThread);
    }

    printf("Server listening on port %d...\n", PORT);

    // 5. 接收客户端连接
    while (true)
    {
        SOCKET clientSocket = accept(listenSocket, NULL, NULL);
        if (clientSocket == INVALID_SOCKET)
            continue;

        // 6. 将 clientSocket 关联到 IOCP
        CreateIoCompletionPort((HANDLE)clientSocket, g_hIOCP, (ULONG_PTR)clientSocket, 0);

        // 7. 分配 IO 数据结构，开始异步接收
        IOData *pIOData = new IOData();
        pIOData->buffer.buf = pIOData->data;
        pIOData->buffer.len = BUFFER_SIZE;

        ZeroMemory(&pIOData->overlapped, sizeof(OVERLAPPED));
        DWORD flags = 0;
        WSARecv(clientSocket, &pIOData->buffer, 1, NULL, &flags, &pIOData->overlapped, NULL);
    }

    // 8. 关闭服务器
    WSACleanup();
    system("pause");
    return 0;
}
