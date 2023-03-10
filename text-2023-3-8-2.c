#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct Node
{
    int val;
    struct Node* next;
    struct Node* random;
};
struct Node* FindRandom(struct Node* random, struct Node* newhead, struct Node* head)
{
    struct Node* cur = head, * ret = newhead;
    while (cur != random)
    {
        cur = cur->next;
        ret = ret->next;
    }
    return ret;
}
struct Node* BuyNode(struct Node* tail)
{
    struct Node* newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    else
    {
        newnode->val = tail->val;
        newnode->next = tail->next;
        newnode->random = NULL;
        return newnode;
    }
}
struct Node* copyRandomList(struct Node* head) {
    struct Node* newhead = NULL, * tail, * newnode, * newtail, * cur1 = head, * cur2, * ret;
    if (!head)
        return NULL;
    tail = head;
    if (newnode = BuyNode(tail))
        newhead = newnode;
    newtail = newhead;
    tail = tail->next;
    while (tail)
    {
        newnode = BuyNode(tail);
        if (newnode == NULL)
            break;
        newtail->next = newnode;
        newtail = newtail->next;
        tail = tail->next;
    }
    cur2 = newhead;
    while (cur1)
    {
        if (!cur1->random)
            cur2->random = NULL;
        else
        {
            ret = FindRandom(cur1->random, newhead, head);
            cur2->random = ret;
            ret = NULL;
        }
        cur2 = cur2->next;
        cur1 = cur1->next;
    }
    return newhead;
}
int main()
{
    return 0;
}