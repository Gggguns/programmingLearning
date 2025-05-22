#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1, * cur2 = l2;
        ListNode* head = new ListNode;
        ListNode* tail = head;
        int carry = 0;
        while (cur1 && cur2)
        {
            carry += (cur1->val + cur2->val);
            cur1 = cur1->next;
            cur2 = cur2->next;
            ListNode* Node = new ListNode(carry % 10);
            carry /= 10;
            tail->next = Node;
            tail = tail->next;
        }
        while (cur1)
        {
            carry += (cur1->val);
            ListNode* Node = new ListNode(carry % 10);
            carry /= 10;
            tail->next = Node;
            tail = tail->next;
            cur1 = cur1->next;
        }
        while (cur2)
        {
            carry += (cur2->val);
            ListNode* Node = new ListNode(carry % 10);
            carry /= 10;
            tail->next = Node;
            tail = tail->next;
            cur2 = cur2->next;
        }
        while (carry)
        {
            ListNode* Node = new ListNode(carry % 10);
            carry /= 10;
            tail->next = Node;
            tail = tail->next;
        }
        ListNode* des = head;
        head = head->next;
        delete des;
        return head;
    }
};
int main()
{
    return 0;
}