#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		next = NULL;
	}
};

class Solution {
	ListNode* mergetList(ListNode* l1, ListNode* l2) {
		ListNode* resHead = new ListNode(0);
		ListNode* resTail = resHead;

		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				resTail->next = new ListNode(l1->val);
				l1 = l1->next;
			}
			else {
				resTail->next = new ListNode(l2->val);
				l2 = l2->next;
			}
			resTail = resTail->next;
		}

		resTail->next = (l1 == NULL) ? l2 : l1;

		return resHead->next;
	}

	ListNode* getMid(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head->next;

		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;
	}

public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode* mid = getMid(head);
		ListNode* rightNode = mid->next;

		mid->next = NULL;

		ListNode* left = sortList(head);
		ListNode* right = sortList(rightNode);

		return mergetList(left, right);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}