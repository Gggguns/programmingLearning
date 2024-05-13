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
    ListNode* kReverse(ListNode* head, int level) {
        if (level == 1)return head;
        ListNode* next = head->next;
        ListNode* newHead = kReverse(next, level - 1);
        head->next = nullptr;
        next->next = head;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode Ret;
        Ret.next = head;
        ListNode* fast = &Ret, * slow = &Ret;
        while (fast) {
            for (int i = 0;i < k;i++) {
                if (fast == nullptr)break;
                fast = fast->next;
            }
            if (fast) {
                ListNode* tail = slow->next, * next = fast->next;
                slow->next = kReverse(slow->next, k);
                slow = tail;
                fast = slow;
                tail->next = next;
            }
        }
        return Ret.next;
    }
};
int main() {
    return 0;
}