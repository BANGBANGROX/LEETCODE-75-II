#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.compare("0") == 0 || num2.compare("0") == 0) return "0";

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		int m = num1.size();
		int n = num2.size();
		string ans = string(m + n, '0');

		for (int i = 0; i < m; ++i) {
			int digit1 = num1[i] - '0';
			for (int j = 0; j < n; ++j) {
				int digit2 = num2[j] - '0';
				int place = i + j;
				int carry = ans[place] - '0';
				int newProduct = digit1 * digit2 + carry;
				int value = newProduct % 10;
				ans[place] = (value + '0');
				ans[place + 1] += (newProduct / 10);
			}
		}

		if (ans.back() == '0') ans.pop_back();

		reverse(ans.begin(), ans.end());

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string num1, num2;
		cin >> num1 >> num2;

		Solution solution;
		cout << solution.multiply(num1, num2) << endl;
	}

	return 0;
}