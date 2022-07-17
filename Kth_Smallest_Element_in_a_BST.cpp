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
	int index;

	void inorder(TreeNode* root, int k) {
		if (root == NULL) return;

		inorder(root->left, k);
		
		++index;
		if (index == k) {
			ans = root->val;
			return;
		}

		inorder(root->right, k);
	}

public:
	int kthSmallest(TreeNode* root, int k) {
		ans = -1;
		index = 0;

		inorder(root, k);

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