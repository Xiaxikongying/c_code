#include <iostream>
#include <time.h>
using namespace std;

typedef struct Node
{
    int key;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
    int count;
} Stack;

Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->key = key;
    return p;
}
Stack *getNewStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->count = 0;
    return s;
}

int isEmpty(Stack *s)
{
    if (s == NULL)
        return 0;
    if (s->count == 0)
        return 1;
    return 0;
}

void push(Stack *s, int key)
{
    if (s == NULL)
        return;
    Node *p = getNewNode(key);
    p->next = s->top;
    s->top = p;
    s->count++;
}

void pop(Stack *s)
{
    if (s == NULL)
        return;
    if (isEmpty(s))
        return;
    cout << "删除的元素是 " << s->top->key << endl;
    Node *p = s->top;
    s->top = p->next;
    free(p);
    s->count--;
}

Node *Top(Stack *s)
{
    if (isEmpty(s))
        exit(1);
    return s->top;
}

int Count(Stack *s)
{
    return s->count;
}

void clear(Stack **s)
{
    while (!isEmpty(*s))
        pop(*s);
    return;
}

void destroy(Stack **s)
{
    clear(s);
    free(*s);
    return;
}

void output(Stack *s)
{
    if (s == NULL)
        return;
    if (isEmpty(s))
    {
        cout << "栈为空" << endl;
        return;
    }
    cout << endl;
    cout << "这个栈的count为: " << s->count << endl;
    Node *p = s->top;
    while (p)
    {
        cout << p->key << " ";
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Stack *s = getNewStack();
    srand(time(0));
    int a;
    for (int i = 0; i < 8; i++)
    {
        a = rand() % 50;
        push(s, a);
        cout << a << endl;
    }
    output(s);
    cout << endl;

    pop(s);
    pop(s);
    pop(s);
    output(s);

    cout << endl;
    clear(&s);
    destroy(&s);

    system("pause");
    return 0;
}