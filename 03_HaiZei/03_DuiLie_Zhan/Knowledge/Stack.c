#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  栈 先进后出
// ****  栈 是用于处理具有  *完全包含* 关系的问题

typedef struct Stack
{
    int *data;
    int size, top;

} Stack;

Stack * initStack(int n)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

void clearStack(Stack *s)
{
    if (s == NULL)
        return;
    free(s->data);
    free(s);
    return;
}

int empty(Stack *s)
{
    return s->top == -1;
}
int FindTop(Stack *s)
{
    if (empty(s))
        return 0;
    return s->data[s->top];
}
int push(Stack *s, int val)
{
    if (s->top == s->size - 1)
        return 0;
    s->top++;
    s->data[s->top] = val;
    return 1;
}
int pop(Stack *s)
{
    if (empty(s))
        return 0;
    s->top--;
    return 1;
}
void printStack(Stack *s)
{
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%4d", s->data[i]);
    }
    printf("\n\n\n");
    return;
}

#define Max_op 10
int main()
{
    srand(time(0));
    Stack *s = initStack(5);
    for (int i = 0; i < Max_op; i++)
    {
        int op = rand() % 3, val = rand() % 100;
        switch (op)
        {
        case 0:
            printf("pop stack,item = %d \n", FindTop(s));
            pop(s);
            break;
        case 1:
        case 2:
            printf("push stack,item = %d \n", val);
            push(s, val);
            break;
        }
        printStack(s);
    }
    clearStack(s);
    system("pause");
    return 0;
}