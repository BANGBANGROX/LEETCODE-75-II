#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();

		if (n == 1) return nums[0];

		int a = nums[0];
		int b = max(nums[0], nums[1]);

		for (int i = 2; i < n; ++i) {
			int c = max(b, a + nums[i]);
			a = b;
			b = c;
		}

		return b;
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
		cout << solution.rob(nums) << endl;
	}

	return 0;
}