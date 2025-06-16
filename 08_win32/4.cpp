#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#define MAX_BUFF_SIZE 1024

// 定义重叠结构体
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
    // 初始化Windows Socket库
    WSAData wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    // 创建socket监听客户端连接
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8888);
    // 绑定地址和端口
    iResult = bind(listenSocket, (sockaddr *)&serverAddr, sizeof(serverAddr));
    // 开始监听
    iResult = listen(listenSocket, SOMAXCONN);

    // 创建IOCP
    HANDLE iocpHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    // 将监听socket关联到IOCP上
    CreateIoCompletionPort((HANDLE)listenSocket, iocpHandle, 0, 0);

    while (true)
    {
        sockaddr_in clientAddr;
        int addrLen = sizeof(clientAddr);
        // 接收客户端连接
        SOCKET clientSocket = accept(listenSocket, (sockaddr *)&clientAddr, &addrLen);
        // 将客户端socket关联到IOCP上
        HANDLE clientHandle = CreateIoCompletionPort((HANDLE)clientSocket, iocpHandle, 0, 0);
        // 创建重叠结构体
        LPPER_IO_OPERATION_DATA perIoData = new PER_IO_OPERATION_DATA();
        memset(&(perIoData->Overlapped), 0, sizeof(WSAOVERLAPPED));
        perIoData->DataBuf.len = MAX_BUFF_SIZE;
        perIoData->DataBuf.buf = perIoData->Buffer;

        DWORD bytesRecv = 0;
        DWORD flags = 0;

        // 接收客户端数据
        WSARecv(clientSocket, &(perIoData->DataBuf), 1, &bytesRecv, &flags, &(perIoData->Overlapped), NULL);
        std::cout << "Client connected: " << inet_ntoa(clientAddr.sin_addr) << ":" << ntohs(clientAddr.sin_port) << std::endl;
    }

    CloseHandle(iocpHandle);
    closesocket(listenSocket);
    WSACleanup();
    return 0;
}