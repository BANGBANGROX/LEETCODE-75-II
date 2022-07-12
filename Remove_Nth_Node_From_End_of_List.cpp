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
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* prev = NULL;
		int count = 0;

		while (count < n) {
			++count;
			fast = fast->next;
		}

		while (fast != NULL) {
			prev = slow;
			fast = fast->next;
			slow = slow->next;
		}

		assert(head != NULL);
		if (prev == NULL) return head->next;

		assert(prev != NULL && slow != NULL);
		prev->next = slow->next;

		return head;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}