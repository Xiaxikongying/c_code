//服务端代码
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

void reverse_string(char *str)
{
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

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

    while (1)
    {
        // 接收客户端消息
        msgrcv(message_id, &message, sizeof(message), 1, 0);
        printf("接收到客户端消息：%s\n", message.message_text);

        // 反转字符串
        reverse_string(message.message_text);

        // 发送回传消息给客户端
        message.message_type = 2;
        msgsnd(message_id, &message, sizeof(message), 0);

        // 检查是否退出
        if (strcmp(message.message_text, "exit") == 0)
        {
            break;
        }
    }

    return 0;
}