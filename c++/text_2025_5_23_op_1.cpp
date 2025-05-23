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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = head;
        if (prev == nullptr)return head;
        ListNode* cur = prev->next;
        if (cur == nullptr)return head;
        ListNode* newhead = new ListNode();
        newhead->next = head;
        ListNode* next = nullptr, * tail = newhead;
        while (cur)
        {
            next = cur->next;
            tail->next = cur;
            tail = tail->next;
            tail->next = prev;
            tail = tail->next;
            tail->next = next;
            prev = next;
            if (prev)cur = prev->next;
            else cur = nullptr;
        }
        ListNode* des = newhead;
        head = newhead->next;
        delete des;
        return head;
    }
};
int main()
{
    return 0;
}