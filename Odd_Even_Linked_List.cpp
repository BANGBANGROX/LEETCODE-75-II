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
	ListNode* oddEvenList(ListNode* head) {
		ListNode* oddHead = new ListNode(0);
		ListNode* oddTail = oddHead;
		ListNode* evenHead = new ListNode(0);
		ListNode* evenTail = evenHead;
		bool isOdd = true;

		while (head != NULL) {
			if (isOdd) {
				oddTail->next = new ListNode(head->val);
				oddTail = oddTail->next;
			}
			else {
				evenTail->next = new ListNode(head->val);
				evenTail = evenTail->next;
			}
			head = head->next;
			isOdd = !isOdd;
		}

		oddTail->next = evenHead->next;

		return oddHead->next;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}