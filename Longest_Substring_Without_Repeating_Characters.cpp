#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		int ans = 0;
		int l = 0;
		unordered_map<int, int> count;

		for (int r = 0; r < n; ++r) {
			++count[s[r] - 'a'];
			while (count[s[r] - 'a'] > 1) {
				--count[s[l] - 'a'];
				++l;
			}
			ans = max(ans, r - l + 1);
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
		cout << solution.lengthOfLongestSubstring(s) << endl;
	}

	return 0;
}