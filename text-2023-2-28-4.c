#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* ret = NULL;
    struct ListNode* connect = NULL;
    struct ListNode* first = list2;
    struct ListNode* Insert = list1;
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    if (list1->val < list2->val)
    {
        ret = list1;
        Insert = list1;
        first = list2;
    }
    else
    {
        ret = list2;
        Insert = list2;
        first = list1;
    }
    while (Insert->next && first)
    {
        if (first->val < Insert->next->val)
        {
            connect = Insert->next;
            Insert->next = first;
            first = first->next;
            Insert->next->next = connect;
        }
        else
        {
            Insert = Insert->next;
        }
    }
    if (Insert->next == NULL)
        Insert->next = first;
    return ret;
}
int main()
{
	return 0;
}