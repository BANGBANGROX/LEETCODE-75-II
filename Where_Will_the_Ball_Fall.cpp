#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findBall(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<int> ans(n);

		for (int ball = 0; ball < n; ++ball) {
			int currentPos = ball;
			for (int i = 0; i < m; ++i) {
				int nextPos = currentPos + grid[i][currentPos];
				if (nextPos < 0 || nextPos >= n || grid[i][currentPos] != grid[i][nextPos]) {
					currentPos = -1;
					break;
				}
				currentPos = nextPos;
			}
			ans[ball] = currentPos;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>> grid(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
			}
		}

		Solution solution;
		vector<int> ans = solution.findBall(grid);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}