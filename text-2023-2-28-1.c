#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
    
};
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* first = head;
    struct ListNode* second = head->next;
    struct ListNode* mid = second;
    first->next = NULL;
    while (mid)
    {
        mid = second->next;
        second->next = first;
        first = second;
        second = mid;
    }
    return first;
}

int main()
{
	return 0;
}