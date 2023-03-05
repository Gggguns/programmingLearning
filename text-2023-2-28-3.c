#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    struct ListNode* slow, * fast;
    slow = pListHead;
    fast = pListHead;
    while (k--)
    {
        if (fast == NULL)
            return NULL;
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int main()
{
	return 0;
}