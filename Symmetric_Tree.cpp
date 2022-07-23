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
	bool isEqual(TreeNode* p, TreeNode* q) {
		if (p == NULL || q == NULL) return (p == NULL && q == NULL);

		return p->val == q->val && isEqual(p->left, q->right) && isEqual(p->right, q->left);
	}

public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;

		return isEqual(root->left, root->right);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}