#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // 子进程
        printf("这是子进程\n");
        sleep(2); // 子进程休眠2秒
        printf("子进程结束\n");
    }
    else
    {
        // 父进程
        printf("这是父进程\n");
        sleep(1); // 父进程休眠1秒
        printf("父进程结束\n");
    }

    return 0;
}
