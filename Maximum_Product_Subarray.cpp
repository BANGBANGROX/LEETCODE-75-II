#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int maxProduct = 1;
		int minProduct = 1;
		int ans = INT_MIN;

		for (int num : nums) {
			if (num < 0) swap(maxProduct, minProduct);
			maxProduct = max(num, maxProduct * num);
			minProduct = min(num, minProduct * num);
			ans = max(ans, maxProduct);
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

		Solution solution;
		cout << solution.maxProduct(nums) << endl;
	}

	return 0;
}