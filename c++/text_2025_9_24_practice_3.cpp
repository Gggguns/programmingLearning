#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        // write code here
        ListNode hhead(0);
        hhead.next = head;
        ListNode* tail = &hhead, * cur = &hhead, * next = nullptr, * newTail = nullptr;
        int i = 0;
        while (cur)
        {
            next = cur->next;
            i++;
            cur = next;
            if (i == k && cur)
            {
                next = cur->next;
                cur->next = nullptr;
                newTail = tail->next;
                tail->next = Reverse(newTail);
                newTail->next = next;
                tail = newTail;
                newTail = nullptr;
                cur = tail;
                i = 0;
            }
        }
        return hhead.next;
    }
    ListNode* Reverse(ListNode* head)
    {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        ListNode* next = head->next;
        ListNode* newHead = Reverse(next);
        head->next = nullptr;
        next->next = head;
        return newHead;
    }
};

int main()
{
    int i = 1;
    ListNode test(0);
    ListNode* testTail = &test;
    for (i = 1; i < 6; i++)
    {
        testTail->next = new ListNode(i);
        testTail = testTail->next;
    }
    Solution s;
    s.reverseKGroup(test.next, 2);
    return 0;
}