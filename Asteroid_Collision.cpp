#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		int n = asteroids.size();
		vector<int> ans;

		ans.push_back(asteroids[0]);

		for (int i = 1; i < n; ++i) {
			bool flag = false;
			while (!ans.empty() && ans.back() > 0 && asteroids[i] < 0) {
				int positiveValue = ans.back();
				int negativeValue = -1 * asteroids[i];
				if (positiveValue == negativeValue) {
					flag = true;
					ans.pop_back();
					break;
				}
				if (positiveValue > negativeValue) {
					flag = true;
					ans.pop_back();
				}
				else ans.pop_back();
			}
			if (!flag) ans.push_back(asteroids[i]);
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
		vector<int> asteroids(n);
		for (int& x : asteroids) cin >> x;

		Solution solution;
		vector<int> ans = solution.asteroidCollision(asteroids);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}