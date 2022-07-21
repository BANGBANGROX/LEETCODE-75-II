#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		int totalSum = accumulate(nums.begin(), nums.end(), 0);

		if ((totalSum & 1) > 0) return false;

		int subsetSum = totalSum / 2;
		vector<bool> dp(subsetSum + 1);

		dp[0] = true;

		for (int num : nums) {
			for (int sum = subsetSum; sum > 0; --sum) {
				if (sum >= num) dp[sum] = dp[sum] | dp[sum - num];
			}
		}

		return dp[subsetSum];
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
		if (solution.canPartition(nums)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}