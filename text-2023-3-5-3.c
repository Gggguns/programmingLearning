#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
  struct ListNode {
     int val;
    struct ListNode *next;
 };
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA = headA, * tailB = headB;
    struct ListNode* longhead = headA, * shorthead = headB;
    int lenA = 0, lenB = 0;
    while (tailA)
    {
        lenA++;
        tailA = tailA->next;
    }
    while (tailB)
    {
        lenB++;
        tailB = tailB->next;
    }
    int gas = abs(lenA - lenB);
    if (lenA < lenB)
    {
        longhead = headB;
        shorthead = headA;
    }
    while (gas--)
    {
        longhead = longhead->next;
    }
    while (longhead != shorthead)
    {
        longhead = longhead->next;
        shorthead = shorthead->next;
    }
    return longhead;
}
int main()
{
    return 0;
}