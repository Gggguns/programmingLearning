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
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        ListNode hhead(0);
        hhead.next = head;
        int i = 0;
        ListNode* cur = &hhead;
        ListNode* next = nullptr, * tail = nullptr, * localhead = nullptr;
        while (cur) {
            i++;
            next = cur->next;
            if (i == m)localhead = cur;
            if (i == n) {
                tail = next->next;
                next->next = nullptr;
                break;
            }
            cur = next;
        }
        if (localhead) {
            cur = localhead->next;
            localhead->next = tail;
            while (cur) {
                next = cur->next;
                cur->next = localhead->next;
                localhead->next = cur;
                cur = next;
            }
        }

        return hhead.next;
    }
};

int main()
{
    return 0;
}