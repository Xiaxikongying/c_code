#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX_WORKSET 10
#define WINDOW_SIZE 20
int mempage = 10;
int procArray[WINDOW_SIZE];
int win[MAX_WORKSET][2];
double maxRate = 0.8, minRate = 0.2;
double curRate;
int cur_workset = 3;
int conflictCount = 0;
void print()
{
    curRate = (double)conflictCount / (double)WINDOW_SIZE;
    printf("缺页故障率：%g,故障率上限/下限：%g/%g\n", curRate, maxRate, minRate);
}
void changeArray()
{
    int i;
    for (i = 0; i < WINDOW_SIZE; i++)
    {
        procArray[i] = rand() % mempage;
    }
    printf("进程调用页面序列：");
    for (i = 0; i < WINDOW_SIZE; i++)
    {
        printf("%d|", procArray[i]);
    }
    printf("\n");
}
void init()
{
    int i, j;
    // changeArray();
    for (i = 0; i < MAX_WORKSET; i++)
    {
        win[i][0] = -1;
        win[i][1] = cur_workset;
    }
}
void changePage(int number)
{
    int i, flag = 0;
    for (i = 1; i < cur_workset; i++)
    {
        if (win[flag][1] <= win[i][1])
        {
            flag = i;
        }
    }
    win[flag][0] = procArray[number];
    win[flag][1] = 1;
    conflictCount++;
    for (i = 0; i < cur_workset; i++)
    {
        if (i != flag && win[i][1] != -1)
        {
            win[i][1]++;
        }
    }
}
void step(int number)
{
    int i, hit = 0;
    for (i = 0; i < cur_workset; i++)
    {
        if (procArray[number] == win[i][0])
        {
            // number++;
            hit = 1;
            break;
        }
    }
    if (hit == 0)
    {
        changePage(number);
    }
}
void run()
{
    int i;
    conflictCount = 0;
    changeArray();
    for (i = 0; i < WINDOW_SIZE; i++)
    {
        step(i);
    }
    printf("冲突次数：%d,", conflictCount);
}
void feedback()
{
    curRate = (double)conflictCount / (double)WINDOW_SIZE;
    if (curRate > maxRate)
    {
        cur_workset++;
    }
    else if (curRate < minRate)
    {
        cur_workset--;
    }
}
int main()
{
    init();
    char quit;
    do
    {
        run();
        print();
        feedback();
        printf("输入任意字符继续，q退出\n");
        scanf("%c", &quit);
        getchar();
    } while (quit != 'q');
}