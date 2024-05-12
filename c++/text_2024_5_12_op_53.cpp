#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
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
    ListNode* Reverse(ListNode* head) {
        if (head->next == nullptr)return head;
        ListNode* next = head->next;
        ListNode* newHead = Reverse(next);
        head->next = nullptr;
        next->next = head;
        return newHead;
    }
    void reorderList(ListNode* head) {
        int sz = 0;
        ListNode* tail = head;
        //计算节点个数
        while (tail) {
            sz++;
            tail = tail->next;
        }
        if (sz < 3)return;
        //找中间节点
        ListNode* mid = head;
        ListNode* prev = mid;
        sz /= 2;
        while (sz && mid) {
            prev = mid;
            mid = mid->next;
            sz--;
        }
        if (prev)prev->next = nullptr;
        //逆序
        ListNode* tail1 = head;
        ListNode* tail2 = Reverse(mid);
        //合并
        ListNode* Ret = new ListNode;
        tail = Ret;
        while (tail1 || tail2) {
            if (tail1) {
                tail->next = tail1;
                tail1 = tail1->next;
                tail = tail->next;
            }
            if (tail2) {
                tail->next = tail2;
                tail2 = tail2->next;
                tail = tail->next;
            }
        }
        ListNode* des = Ret;
        Ret = Ret->next;
        delete des;
        head = Ret;
    }
};
int main() {
    Solution s;
    vector<int> v{ 1,2,3,4 };
    ListNode head;
    ListNode* tail = &head;
    for (auto e : v) {
        tail->next = new ListNode(e);
        tail = tail->next;
    }
    s.reorderList(head.next);
    tail = &head;
    while (tail) {
        ListNode* des = tail;
        tail = tail->next;
        delete des;
    }
	return 0;
}