#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        if (slow == nullptr) return;
        ListNode* fast = head->next;
        // 找中间节点
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)fast = fast->next;
        }

        // 逆转中间节点之后的链表
        ListNode* head1 = head;
        ListNode* head2 = new ListNode();
        ListNode* cur = slow->next;
        slow->next = nullptr;
        ListNode* next = nullptr;
        while (cur)
        {
            next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = next;
        }
        ListNode* rethead = new ListNode();
        ListNode* des = head2;
        ListNode* tail = rethead;
        head2 = head2->next;
        delete des;
        des = nullptr;
        while (head1 && head2)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
        while (head1)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        while (head2)
        {
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
        des = rethead;
        rethead = rethead->next;
        delete des;
        head = rethead;
    }
};
int main()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = nullptr;
    Solution s;
    s.reorderList(&node1);
    return 0;
}