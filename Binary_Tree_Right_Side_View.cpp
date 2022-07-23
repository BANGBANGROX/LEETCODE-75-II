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
	vector<int> rightSideView(TreeNode* root) {
		if (root == NULL) return {};

		vector<int> ans;
		queue<TreeNode*> q;

		q.push(root);

		while (!q.empty()) {
			bool firstNode = true;
			int n = q.size();
			for (int i = 0; i < n; ++i) {
				TreeNode* node = q.front();
				q.pop();
				if (firstNode) {
					ans.push_back(node->val);
					firstNode = false;
				}
				if (node->right != NULL) q.push(node->right);
				if (node->left != NULL) q.push(node->left);
			}
		}

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