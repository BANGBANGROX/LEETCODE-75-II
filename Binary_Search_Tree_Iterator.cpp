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

class BSTIterator {
	vector<int> inorder;
	int ptr;

	void setInorder(TreeNode* root) {
		if (root == NULL) return;

		setInorder(root->left);

		inorder.push_back(root->val);

		setInorder(root->right);
	}

public:
	BSTIterator(TreeNode* root) {
		setInorder(root);

		ptr = -1;
	}

	int next() {
		++ptr;

		return inorder[ptr];
	}

	bool hasNext() {
		return ptr < (int)inorder.size() - 1;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}