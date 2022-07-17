#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();

		for (int i = 0; i < m; ++i) {
			if (matrix[i][0] > target) break;
			if (matrix[i].back() < target) continue;
			if (binary_search(matrix[i].begin(), matrix[i].end(), target)) return true;
		}

		return false;
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
		int target;
		cin >> target;

		Solution solution;
		cout << solution.searchMatrix(matrix, target) << endl;
	}

	return 0;
}