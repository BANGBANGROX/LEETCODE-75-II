#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int l = newInterval[0];
		int r = newInterval[1];
		int i = 0;
		int n = intervals.size();
		vector<vector<int>> ans;

		while (i < n && intervals[i][1] < l) {
			++i;
		}

		intervals.insert(intervals.begin() + i, newInterval);
		++n;

		ans.push_back(intervals[0]);

		for (int i = 1; i < n; ++i) {
			int newL = intervals[i][0];
			int newR = intervals[i][1];
			if (newL <= ans.back()[1]) {
				int start = min(ans.back()[0], newL);
				int end = max(ans.back()[1], newR);
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
		vector<int> newInterval(2);
		cin >> newInterval[0] >> newInterval[1];

		Solution solution;
		vector<vector<int>> ans = solution.insert(intervals, newInterval);
		for (vector<int>& x : ans) {
			cout << x[0] << " " << x[1] << endl;
		}
	}

	return 0;
}