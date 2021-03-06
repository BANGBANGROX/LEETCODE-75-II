#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<int> st;
		int n = s.size();
		char currentOperation = '+';
		int currentNumber = 0;
		int ans = 0;

		for (int i = 0; i < n; ++i) {
			if (isdigit(s[i])) {
				currentNumber = currentNumber * 10 + (s[i] - '0');
			}
			if ((!isdigit(s[i]) && !iswspace(s[i])) || i == n - 1) {
				if (currentOperation == '-') {
					st.push(-1 * currentNumber);
				}
				if (currentOperation == '+') {
					st.push(currentNumber);
				}
				if (currentOperation == '*') {
					int a = st.top();
					st.pop();
					st.push(a * currentNumber);
				}
				if (currentOperation == '/') {
					int a = st.top();
					st.pop();
					st.push(a / currentNumber);
				}
				currentNumber = 0;
				currentOperation = s[i];
			}
		}

		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		cout << solution.calculate(s) << endl;
	}

	return 0;
}