#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
#include <iterator>
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		//统计链表节点个数
		long long size1 = 0, size2 = 0;
		ListNode* cur = pHead1;
		while (cur) {
			size1++;
			cur = cur->next;
		}
		cur = pHead2;
		while (cur) {
			size2++;
			cur = cur->next;
		}
		long long diff = size1 - size2;
		ListNode* fast = pHead1, * slow = pHead2;
		if (diff > 0) {
			while (diff--) {
				fast = fast->next;
			}
		}
		else {
			while (diff++) {
				slow = slow->next;
			}
		}
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
	}
};
int main() {
	return 0;
}