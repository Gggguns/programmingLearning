#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int val;
    struct Node* next;
    struct Node* random;
    
};
struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    //插入拷贝到原节点后面
    while (cur)
    {
        struct Node* copy = malloc(sizeof(struct Node));
        struct Node* next = cur->next;
        if (copy)
        {
            copy->val = cur->val;
            copy->next = next;
        }
        cur->next = copy;
        cur = next;
    }
    cur = head;
    //拷贝random
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = next;
    }
    //分离拷贝节点并还原原链表
    cur = head;
    struct Node* copyhead = NULL, * copytail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        //尾插
        if (copyhead)
        {
            copytail->next = copy;
            copytail = copy;
        }
        else
            copyhead = copytail = copy;
        cur->next = next;
        cur = next;
    }
    return copyhead;
}
int main()
{
    return 0;
}