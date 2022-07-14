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
	bool ans;

	int isBalancedUtil(TreeNode* root) {
		if (root == NULL) return 0;

		int left = isBalancedUtil(root->left);
		int right = isBalancedUtil(root->right);

		if (abs(right - left) > 1) {
			ans = false;
		}

		return max(left, right) + 1;
	}
public:
	bool isBalanced(TreeNode* root) {
		ans = true;

		isBalancedUtil(root);

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