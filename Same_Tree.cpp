#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		left = right = NULL;
	}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL || q == NULL) return (p == NULL && q == NULL);

		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}