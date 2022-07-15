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

	void pathSumUtil(TreeNode* root, vector<int>& nodes, int target) {
		if (root == NULL) return;

		nodes.push_back(root->val);

		pathSumUtil(root->left, nodes, target);
		pathSumUtil(root->right, nodes, target);

		long sum = 0;

		for (int i = nodes.size() - 1; i >= 0; --i) {
			sum += nodes[i];
			if (sum == target) ++ans;
		}

		nodes.pop_back();
	}

public:
	int pathSum(TreeNode* root, int targetSum) {
		vector<int> nodes;
		ans = 0;

		pathSumUtil(root, nodes, targetSum);

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