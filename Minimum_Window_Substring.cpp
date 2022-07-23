#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int m = s.size();
		vector<int> countS(256);
		vector<int> countT(256);
		int needed = 0;
		int done = 0;
		int l = 0;
		int start = 0;
		int len = INT_MAX;

		for (char ch : t) {
			if (countT[ch] == 0) ++needed;
			++countT[ch];
		}

		for (int r = 0; r < m; ++r) {
			++countS[s[r]];
			if (countS[s[r]] == countT[s[r]]) ++done;
			if (done == needed) {
				while (countS[s[l]] > countT[s[l]]) {
					--countS[s[l]];
					++l;
				}
				int currentLength = r - l + 1;
				if (currentLength < len) {
					len = currentLength;
					start = l;
				}
			}
		}

		if (len == INT_MAX) return "";

		return s.substr(start, len);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s, t;
		cin >> s >> t;

		Solution solution;
		cout << solution.minWindow(s, t) << endl;
	}

	return 0;
}