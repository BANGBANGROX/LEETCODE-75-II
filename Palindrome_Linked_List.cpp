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
	ListNode* left;
	bool ans;

	void isPalindromeUtil(ListNode* right) {
		if (right == NULL) return;

		isPalindromeUtil(right->next);

		if (!ans) return;

		if (right->val != left->val) {
			ans = false;
			return;
		}

		left = left->next;
	}

public:
	bool isPalindrome(ListNode* head) {
		left = head;
		ans = true;

		isPalindromeUtil(head);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}