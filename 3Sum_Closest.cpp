#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size();
		int minDifference = INT_MAX;
		int ans = 0;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < n - 2; ++i) {
			int l = i + 1;
			int r = n - 1;
			while (l < r) {
				int sum = nums[l] + nums[r] + nums[i];
				if (abs(sum - target) < minDifference) {
					minDifference = abs(sum - target);
					ans = nums[l] + nums[r] + nums[i];
				}
				if (sum > target) --r;
				else ++l;
			}
		}

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
		int target;
		cin >> target;

		Solution solution;
		cout << solution.threeSumClosest(nums, target) << endl;
	}

	return 0;
}