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
        printf("这是子进程\n");
    else
        printf("这是父进程\n");
    return 0;
}
