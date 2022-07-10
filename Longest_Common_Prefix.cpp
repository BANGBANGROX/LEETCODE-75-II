#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int minLen = INT_MAX;
		string minLenString = "";

		for (string& s : strs) {
			if (minLen > (int)s.size()) {
				minLen = s.size();
				minLenString = s;
			}
		}

		for (int i = minLen; i > 0; --i) {
			bool allMatch = true;
			for (string& s : strs) {
				if (s.substr(0, i).compare(minLenString.substr(0, i)) != 0) {
					allMatch = false;
					break;
				}
			}
			if (allMatch) return minLenString.substr(0, i);
		}

		return "";
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<string> strs(n);
		for (string& x : strs) cin >> x;

		Solution solution;
		cout << solution.longestCommonPrefix(strs) << endl;
	}

	return 0;
}