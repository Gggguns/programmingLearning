#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
    struct cmp
    {
        bool operator()(ListNode* node1, ListNode* node2)
        {
            return node1->val > node2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for (auto list : lists)
        {
            ListNode* cur = list;
            while (cur)
            {
                heap.push(cur);
                cur = cur->next;
            }
        }
        ListNode head;
        ListNode* tail = &head;
        ListNode* node = nullptr;
        while (!heap.empty())
        {
            node = heap.top();
            heap.pop();
            tail->next = node;
            tail = tail->next;
        }
        tail->next = nullptr;
        return head.next;
    }

};
int main()
{
	return 0;
}