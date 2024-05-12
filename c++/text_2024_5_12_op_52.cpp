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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode;
        newHead->next = head;
        ListNode* prev = newHead;
        ListNode* cur1 = prev->next;
        if (cur1 == nullptr || cur1->next == nullptr)return head;
        ListNode* cur2 = cur1->next;
        ListNode* next = cur2->next;
        while (prev && cur1 && cur2) {
            prev->next = cur2;
            cur2->next = cur1;
            cur1->next = next;
            prev = cur1;
            cur1 = prev->next;
            if (cur1)cur2 = cur1->next;
            if (cur2)next = cur2->next;
        }
        ListNode* des = newHead;
        newHead = newHead->next;
        delete des;
        return newHead;
    }
};
int main() {
	return 0;
}