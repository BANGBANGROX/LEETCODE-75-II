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
	int ans;

	int diameterOfBinaryTreeUtil(TreeNode* root) {
		if (root == NULL) return 0;

		int left = diameterOfBinaryTreeUtil(root->left);
		int right = diameterOfBinaryTreeUtil(root->right);

		ans = max(ans, left + right);

		return max(left, right) + 1;
	}

public:
	int diameterOfBinaryTree(TreeNode* root) {
		ans = 0;

		diameterOfBinaryTreeUtil(root);

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