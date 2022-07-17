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
	TreeNode* sortedArrayToBSTUtil(vector<int>& nums, int start, int end) {
		if (start > end) return NULL;

		int mid = (start + end) / 2;

		TreeNode* root = new TreeNode(nums[mid]);

		root->left = sortedArrayToBSTUtil(nums, start, mid - 1);
		root->right = sortedArrayToBSTUtil(nums, mid + 1, end);

		return root;
	}

public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int n = nums.size();

		return sortedArrayToBSTUtil(nums, 0, n - 1);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}