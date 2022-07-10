#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		int m = matrix.size();
		int n = matrix[0].size();
		int firstRow = 0;
		int lastRow = m - 1;
		int firstCol = 0;
		int lastCol = n - 1;

		while (firstRow < lastRow && firstCol < lastCol) {
			// Take the first row
			for (int i = firstCol; i <= lastCol; ++i) {
				ans.push_back(matrix[firstRow][i]);
			}
			++firstRow;
			// Take the last colomn
			for (int i = firstRow; i <= lastRow; ++i) {
				ans.push_back(matrix[i][lastCol]);
			}
			--lastCol;
			// Take the last row
			if (firstRow <= lastRow) {
				for (int i = lastCol; i >= firstCol; --i) {
					ans.push_back(matrix[lastRow][i]);
				}
			}
			--lastRow;
			// Take the first colomn
			if (firstCol <= lastCol) {
				for (int i = lastRow; i >= firstRow; --i) {
					ans.push_back(matrix[i][firstCol]);
				}
			}
			++firstCol;
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
		vector<vector<int>> matrix(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> matrix[i][j];
			}
		}

		Solution solution;
		vector<int> ans = solution.spiralOrder(matrix);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}