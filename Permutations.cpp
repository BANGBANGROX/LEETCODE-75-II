#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool nextPermutation(vector<int>& nums) {
		int n = nums.size();

		if (n == 1) return false;

		int last = n - 2;

		while (last >= 0 && nums[last + 1] <= nums[last]) --last;

		if (last < 0) return false;

		int nextGreater = n - 1;

		for (int i = n - 1; i > last; --i) {
			if (nums[i] > nums[last]) {
				nextGreater = i;
				break;
			}
		}

		swap(nums[nextGreater], nums[last]);

		reverse(nums.begin() + last + 1, nums.end());

		return true;
	}

public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;

		sort(nums.begin(), nums.end());

		do {
			ans.push_back(nums);
		} while (nextPermutation(nums));

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		Solution solution;
		vector<vector<int>> ans = solution.permute(nums);
		for (vector<int>& x : ans) {
			for (int& y : x) {
				cout << y << " ";
			}
			cout << endl;
		}
	}

	return 0;
}