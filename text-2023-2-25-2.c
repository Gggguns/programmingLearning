#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* ElFind(struct ListNode* head, int val)
{
    struct ListNode* ret = head;
    while (ret)
    {
        if (ret->val == val)
            return ret;
        ret = ret->next;
    }
    return ret;
}
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* check = head;
    struct ListNode* connect = NULL;
    struct ListNode* ret = NULL;
    while (ret = ElFind(head, val))
    {
        if (check->val == val)
        {
            head = check->next;
            free(check);
            check = head;
        }
        else
        {
            while ((check->next->val) != val)
            {
                check = check->next;
            }
            connect = check->next->next;
            free(check->next);
            check->next = connect;
        }
    }
    return head;

}
int main()
{
    return 0;
}