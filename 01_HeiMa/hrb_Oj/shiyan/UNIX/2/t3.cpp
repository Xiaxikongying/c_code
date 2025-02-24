#include <stdio.h>
#include <unistd.h>

int main()
{
    int shared_var = 0; // 定义一个共享变量
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // 子进程
        shared_var = 42; // 在子进程中修改共享变量的值
        printf("子进程: shared_var = %d\n", shared_var);
    }
    else
    {
        // 父进程
        printf("父进程: shared_var = %d\n", shared_var); 
    }

    return 0;
}
