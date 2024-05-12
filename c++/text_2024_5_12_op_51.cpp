#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
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
        if (l1 == nullptr)return l2;
        if (l2 == nullptr)return l1;
        int cur = 0;
        ListNode* tail1 = l1;
        ListNode* tail2 = l2;
        ListNode* Ret = new ListNode;
        ListNode* tail = Ret;
        //ПајУ
        while (tail1 && tail2) {
            cur = cur + tail1->val + tail2->val;
            tail1 = tail1->next;
            tail2 = tail2->next;
            tail->next = new ListNode(cur % 10);
            tail = tail->next;
            cur /= 10;
        }
        while (tail1) {
            cur = cur + tail1->val;
            tail1 = tail1->next;
            tail->next = new ListNode(cur % 10);
            tail = tail->next;
            cur /= 10;
        }
        while (tail2) {
            cur = cur + tail2->val;
            tail2 = tail2->next;
            tail->next = new ListNode(cur % 10);
            tail = tail->next;
            cur /= 10;
        }
        while (cur) {
            tail->next = new ListNode(cur % 10);
            tail = tail->next;
            cur /= 10;
        }
        ListNode* Des = Ret;
        Ret = Ret->next;
        delete Des;
        return Ret;
    }
};
int main() {
    return 0;
}