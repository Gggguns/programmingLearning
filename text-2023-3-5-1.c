#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* partition(struct ListNode* pHead, int x) {
    struct ListNode* lguard, * ltail, * gguard, * gtail, * cur;
    lguard = ltail=(struct ListNode*)malloc(sizeof(struct ListNode));
    gguard = gtail = (struct ListNode*)malloc(sizeof(struct ListNode));
    ltail->next = NULL;
    gtail->next = NULL;
    cur = pHead;
    while (cur)
    {
        if (cur->val < x)
        {
            ltail->next = cur;
            ltail = ltail->next;
        }
        else
        {
            gtail->next = cur;
            gtail = gtail->next;
        }
        cur = cur->next;
    }
    gtail->next = NULL;
    ltail->next = gguard->next;
    struct ListNode* newhead = lguard->next;
    free(lguard);
    lguard = NULL;
    free(gguard);
    gguard = NULL;
    return newhead;
}
int main()
{
	return 0;
}