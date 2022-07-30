#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> ans;
	vector<int> candidates;
	set<vector<int>> visited;
	int n;

	void generate(int index, int target, vector<int>& current) {
		if (target == 0) {
			if (visited.find(current) != visited.end()) return;
			ans.push_back(current);
			visited.insert(current);
			return;
		}

		if (index == n || target < 0) return;

		current.push_back(candidates[index]);

		generate(index, target - candidates[index], current);
	
		current.pop_back();

		generate(index + 1, target, current);
	}

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> current;
		this->candidates = candidates;
		n = candidates.size();

		sort(this->candidates.begin(), this->candidates.end());

		generate(0, target, current);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> candidates(n);
		for (int& x : candidates) cin >> x;
		int target;
		cin >> target;

		Solution solution;
		vector<vector<int>> ans = solution.combinationSum(candidates, target);
		for (vector<int>& x : ans) {
			for (int& y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}