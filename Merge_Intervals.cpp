#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());

		int n = intervals.size();
		vector<vector<int>> ans;

		ans.push_back(intervals[0]);

		for (int i = 1; i < n; ++i) {
			int l = intervals[i][0];
			int r = intervals[i][1];
			if (l <= ans.back()[1]) {
				int start = min(ans.back()[0], l);
				int end = max(ans.back()[1], r);
				ans.pop_back();
				ans.push_back({ start,end });
			}
			else ans.push_back(intervals[i]);
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
		vector<vector<int>> intervals(n, vector<int>(2));
		for (vector<int>& x : intervals) {
			cin >> x[0] >> x[1];
		}
		
		Solution solution;
		vector<vector<int>> ans = solution.merge(intervals);
		for (vector<int>& x : ans) cout << x[0] << " " << x[1] << endl;
	}

	return 0;
}