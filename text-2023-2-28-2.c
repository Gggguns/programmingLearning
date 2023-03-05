#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow, * fast;
    slow = head;
    fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
int main()
{
	return 0;
}