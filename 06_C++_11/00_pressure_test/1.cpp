// 该cpp是对五子棋服务端进行压力测试

#include <winsock2.h>
#include <iostream>
#include <thread>
#include <mingw.thread.h>
#include <vector>
using namespace std;
#pragma comment(lib, "ws2_32.lib")

typedef struct STRU_LOGIN_RQ
{
   STRU_LOGIN_RQ() : type(10002)
   {
      memset(tel, 0, sizeof(tel));
      memset(password, 0, sizeof(password));
   }
   int type;
   char tel[40];
   char password[40];

} STRU_LOGIN_RQ;
STRU_LOGIN_RQ rq;
const char *serverIp = "192.168.93.132";
int port = 8000;
int nlen = 84;

void SendData(SOCKET lSendIP, char *szbuf, int nlen)
{
   int DataLen = nlen + 4;
   vector<char> vecbuf;
   vecbuf.resize(DataLen);

   char *buf = &*vecbuf.begin();
   char *tmp = buf;
   *(int *)tmp = nlen; // 先将4字节的长度放入发送包中
   tmp += sizeof(int); // 指针偏移

   memcpy(tmp, szbuf, nlen); // 再将数据部分放入发送包中
   send(lSendIP, buf, DataLen, 0);
}

unsigned __stdcall stress_test(void *lpVoid)
{
   SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

   sockaddr_in serverAddr;
   serverAddr.sin_family = AF_INET;
   serverAddr.sin_port = htons(port);
   serverAddr.sin_addr.s_addr = inet_addr(serverIp);
   connect(clientSocket, (sockaddr *)&serverAddr, sizeof(serverAddr));
   for (int i = 0; i < 1000; ++i)
      SendData(clientSocket, (char *)&rq, sizeof(rq)); // 发送数据
   while (1)
   {
      Sleep(10000);
   }
   closesocket(clientSocket);
   return 0;
}


int main()
{
   strcpy(rq.tel, "13345678910");
   strcpy(rq.password, "1");
   WSADATA wsaData;
   WSAStartup(MAKEWORD(2, 2), &wsaData);
   cout << *(int *)&rq << "   " << sizeof(rq) << endl;
   for (int i = 0; i < 100; ++i)
   {
      cout << i << endl;
      _beginthreadex(NULL, 0, &stress_test, NULL, 0, NULL);
   }
   while (1)
   {
      Sleep(100);
   }
   WSACleanup();
   system("pause");
   return 0;
}

/*
  SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  sockaddr_in serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);
  serverAddr.sin_addr.s_addr = inet_addr(serverIp);

  connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
  cout << "connect success" << endl;

  send(clientSocket, (char*)&rq, sizeof(rq), 0);
  */
