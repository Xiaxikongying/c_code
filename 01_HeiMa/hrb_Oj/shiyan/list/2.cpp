#include <iostream>
using namespace std;

struct node
{
    int data;          //用于存储数据
    struct node *next; //指向下一个数据
};

struct node *creatNode(int data)
{
    struct node *newNode = ( node *)malloc(sizeof(node));
    newNode->data = data;
    return newNode;
}

struct node *creatlist() 
{
    struct node *headNode = (node *)malloc(sizeof(node));
    headNode->next = NULL;
    return headNode;
}



void printlist(struct node *headNode)
{
    struct node *pmove = headNode->next;
    while (pmove)
    {
        cout << pmove->data << " ";
        pmove = pmove->next;
    }
    cout << endl;
}

void insertlist(struct node *headNode, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = headNode->next;
    headNode->next = newNode;
}

void deletelist(struct node *headNode, int data)
{
    struct node *posnode = headNode->next;
    struct node *posnodeFront = headNode;
    if (posnode == NULL)
    {
        cout << "无法找到该数据" << endl;
    }
    else
    {
        while (posnode->data != data)
        {
            posnodeFront = posnode;
            posnode = posnode->next;
            if (posnode == NULL)
            {
                cout << "无法找到该数据" << endl;
                return;
            }
        }
        posnodeFront->next = posnode->next;
        free(posnode);
        }
}

int main()
{
    struct node *list = creatlist();
    insertlist(list, 1);
    insertlist(list, 2); 
    insertlist(list, 3);
    insertlist(list, 4);
    cout << "删除前的列表" << endl;
    printlist(list);
    deletelist(list, 2);
    cout << "删除后的列表" << endl;
    printlist(list);

    system("pause");
    return 0;
}