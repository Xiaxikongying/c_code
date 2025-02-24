//客户端代码
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MESSAGE_SIZE 100

struct message_buffer
{
    long message_type;
    char message_text[MAX_MESSAGE_SIZE];
};

int main()
{
    key_t key;
    int message_id;
    struct message_buffer message;

    // 创建消息队列
    key = ftok("server.c", 'A');
    message_id = msgget(key, 0666 | IPC_CREAT);
    if (message_id == -1)
    {
        perror("msgget");
        exit(1);
    }

    // 循环接收输入字符串并发送到服务器端
    while (1)
    {
        printf("请输入字符串（输入\"exit\"退出）：");
        fgets(message.message_text, MAX_MESSAGE_SIZE, stdin);

        // 移除换行符
        message.message_text[strcspn(message.message_text, "\n")] = '\0';

        // 发送消息
        message.message_type = 1;
        msgsnd(message_id, &message, sizeof(message), 0);

        // 接收服务器端回传消息
        msgrcv(message_id, &message, sizeof(message), 2, 0);
        printf("服务器回传消息：%s\n", message.message_text);

        // 检查是否退出
        if (strcmp(message.message_text, "exit") == 0)
        {
            break;
        }
    }

    // 删除消息队列
    msgctl(message_id, IPC_RMID, NULL);

    return 0;
}