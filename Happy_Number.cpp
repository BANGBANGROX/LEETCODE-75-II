#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
	int digitSquareSum(int n) {
		int res = 0;

		while (n > 0) {
			int dig = n % 10;
			res += dig * dig;
			n /= 10;
		}

		return res;
	}

public:
	bool isHappy(int n) {
		unordered_set<int> visited;

		while (n > 1 && visited.find(n) == visited.end()) {
			visited.insert(n);
			n = digitSquareSum(n);
		}

		return n == 1;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		Solution solution;
		cout << solution.isHappy(n) << endl;
	}

	return 0;
}