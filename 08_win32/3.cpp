#include <windows.h>
#include <iostream>

VOID CALLBACK FileIOCompletionRoutine(
    DWORD dwErrorCode,
    DWORD dwNumberOfBytesTransfered,
    LPOVERLAPPED lpOverlapped)
{
    if (dwErrorCode == 0)
        std::cout << "I/O 操作完成！传输字节数: " << dwNumberOfBytesTransfered << std::endl;
    else
        std::cerr << "I/O 失败，错误码: " << dwErrorCode << std::endl;
}

int main()
{
    HANDLE hFile = CreateFile(
        "test.txt",           // 文件路径
        GENERIC_READ,         // 访问权限
        0,                    // 共享模式
        NULL,                 // 安全属性
        OPEN_EXISTING,        // 打开模式
        FILE_FLAG_OVERLAPPED, // **必须指定 OVERLAPPED**
        NULL);                // 模板文件
    if (hFile == INVALID_HANDLE_VALUE)
    {
        std::cerr << "打开文件失败，错误码: " << GetLastError() << std::endl;
        return 1;
    }

    char buffer[100] = {0}; // 读取缓冲区
    DWORD bytesRead = 0;
    OVERLAPPED overlapped = {0}; // **初始化 OVERLAPPED**

    // 发起异步读取操作
    if (!ReadFileEx(hFile, buffer, sizeof(buffer) - 1, &overlapped, FileIOCompletionRoutine))
    {
        std::cerr << "ReadFileEx 失败，错误码: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        return 1;
    }

    std::cout << "I/O 操作已提交，等待完成..." << std::endl;

    // **等待 I/O 事件完成**  会被异步 I/O唤醒
    SleepEx(INFINITE, TRUE); // 允许 I/O 完成后执行回调

    std::cout << "读取到的数据: " << std::endl
              << buffer << std::endl;

    CloseHandle(hFile);
    system("pause");
    return 0;
}
