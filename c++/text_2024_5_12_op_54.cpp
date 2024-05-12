#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
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
    struct Less {
        bool operator()(ListNode* e1, ListNode* e2) {
            return e1->val > e2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = 0;
        k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, Less> Q;
        for (int i = 0;i < k;i++) {
            ListNode* tail = lists[i];
            ListNode* cur = tail;
            while (tail) {
                tail = tail->next;
                cur->next = nullptr;
                Q.push(cur);
                cur = tail;
            }
        }
        ListNode newHead;
        ListNode* tail = &newHead;
        while (Q.size()) {
            tail->next = Q.top();
            Q.pop();
            tail = tail->next;
        }
        return newHead.next;
    }
};
int main() {
    vector<ListNode*> lists;
    vector<vector<int>> vv{ {1,4,5},{1,3,4},{2,6} };
    lists.resize(vv.size());
    vector<ListNode*> tails;
    tails.resize(vv.size());
    for (int i = 0;i < vv.size();i++) {
        for (int j = 0;j < vv[i].size();j++) {
            if (lists[i]) {
                tails[i]->next=new ListNode(vv[i][j]);
                tails[i] = tails[i]->next;
            }
            else {
                lists[i] = new ListNode(vv[i][j]);
                tails[i] = lists[i];
            }
        }
    }
    Solution s;
    ListNode* head=s.mergeKLists(lists);
    ListNode* tail = head;
    while (tail) {
        cout << tail->val << ' ';
        tail = tail->next;
    }
    tail = head;
    while (tail) {
        ListNode* des = tail;
        tail = tail->next;
        delete des;
    }
	return 0;
}