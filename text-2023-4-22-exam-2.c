#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode
{
    int num;
    struct ListNode* next;
}LNode;

//Âò½Úµã
LNode* BuyNode(int* pi)
{
    LNode* node = (LNode*)malloc(sizeof(LNode));
    if (node)
    {
        node->num = *pi;
        node->next = NULL;
    }
    return node;
}
int main()
{
    int n = 0, m = 0, i = 1;
    LNode* head = BuyNode(&i); 
    LNode* tail = head;
    tail->next = head;
    scanf("%d%d", &n, &m);
    for (i = 2;i < n + 1;i++)
    {
        tail->next = BuyNode(&i);
        tail = tail->next;
        tail->next = head;
    }
    i = 1;
    LNode* cur = head;
    LNode* prev = NULL;
    while (cur->next != cur)
    {
        prev = cur;
        cur = cur->next;
        i++;
        if (i == m )
        {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
            i = 1;
        }
    }
    printf("%d\n", cur->num);
    free(cur);
    cur = NULL;
    return 0;
}