#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* CheckMid(struct ListNode* head)
{
    struct ListNode* slow, * fast;
    slow = head;
    fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
struct ListNode* Reverse(struct ListNode* head)
{
    struct ListNode* cur, * newhead, * save;
    newhead = head;
    cur = head->next;
    newhead->next = NULL;
    while (cur)
    {
        save = newhead;
        newhead = cur;
        cur = cur->next;
        newhead->next = save;

    }
    return newhead;
}
bool chkPalindrome(struct ListNode* head)
 {
        struct ListNode* Mid, * rhead;
        Mid = CheckMid(head);
        rhead = Reverse(Mid);
        while (rhead && head)
        {
            if (rhead->val != head->val)
                return false;
            head = head->next;
            rhead = rhead->next;
        }
        return true;
    
};
int main()
{
	return 0;
}