#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    
    ListNode* dfs(ListNode* L) {
        ListNode* next = L->next;
        if (next == nullptr)return L;
        ListNode* head = dfs(next);
        L->next = nullptr;
        next->next = L;
        return head;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        ListNode* HeadGrade = new ListNode(0);
        head1 = dfs(head1);
        head2 = dfs(head2);
        ListNode* tail1 = head1;
        ListNode* tail2 = head2;
        ListNode* tail = HeadGrade;
        int Carry = 0;
        while (tail1 && tail2) {
            Carry = Carry + tail1->val + tail2->val;
            tail->next = new ListNode(Carry % 10);
            Carry /= 10;
            tail2 = tail2->next;
            tail1 = tail1->next;
            tail = tail->next;
        }
        while (tail1) {
            Carry = Carry + tail1->val;
            tail->next = new ListNode(Carry % 10);
            Carry /= 10;
            tail1 = tail1->next;
            tail = tail->next;
        }
        while (tail2) {
            Carry = Carry + tail2->val;
            tail->next = new ListNode(Carry % 10);
            Carry /= 10;
            tail2 = tail2->next;
            tail = tail->next;
        }
        if (Carry)tail->next = new ListNode(Carry % 10);
        HeadGrade->next = dfs(HeadGrade->next);
        return HeadGrade->next;
    }
};
int main()
{
	return 0;
}