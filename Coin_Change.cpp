#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end());

		vector<int> dp(amount + 1, INT_MAX);

		dp[0] = 0;

		for (int amt = 1; amt <= amount; ++amt) {
			for (int coin : coins) {
				if (coin > amt) break;
				if (dp[amt - coin] != INT_MAX) dp[amt] = min(dp[amt], dp[amt - coin] + 1);
			}
		}

		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> coins(n);
		for (int& x : coins) cin >> x;
		int amount;
		cin >> amount;

		Solution solution;
		cout << solution.coinChange(coins, amount) << endl;
	}

	return 0;
}