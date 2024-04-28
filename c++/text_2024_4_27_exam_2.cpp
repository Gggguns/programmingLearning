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
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		//统计节点个数
		ListNode* tail1 = pHead1;
		ListNode* tail2 = pHead2;
		int sz1 = 0, sz2 = 0;
		while (tail1) {
			sz1++;
			tail1 = tail1->next;
		}
		while (tail2) {
			sz2++;
			tail2 = tail2->next;
		}
		//谁先走
		int n = 0;
		tail1 = pHead1, tail2 = pHead2;
		if (sz2 > sz1) {
			n = sz2 - sz1;
			while (tail2 && n--)tail2 = tail2->next;
		}
		else {
			n = sz1 - sz2;
			while (tail1 && n--)tail1 = tail1->next;
		}
		//一起走
		while (tail1 && tail2) {
			if (tail1->val == tail2->val)return tail1;
			tail1 = tail1->next;
			tail2 = tail2->next;
		}
		return nullptr;
	}
};

int main() {
	return 0;
}