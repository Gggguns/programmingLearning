#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow, * fast, * start, * meet;
    slow = head;
    fast = head;
    start = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            meet = fast;
            while (meet != start)
            {
                meet = meet->next;
                start = start->next;
            }
            return start;
        }
    }
    return NULL;

}
int main()
{
	return 0;
}