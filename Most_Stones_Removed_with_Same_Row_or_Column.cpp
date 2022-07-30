#include<bits/stdc++.h>
using namespace std;

class Solution {
	void dfs(int node, int& componentSize, vector<vector<int>>& graph, vector<bool>& visited) {
		visited[node] = true;

		for (int child : graph[node]) {
			if (!visited[child]) dfs(child, componentSize, graph, visited);
		}

		++componentSize;
	}

public:
	int removeStones(vector<vector<int>>& stones) {
		int n = stones.size();
		int ans = 0;
		vector<vector<int>> graph(n);
		vector<bool> visited(n);

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				int componentSize = -1;
				dfs(i, componentSize, graph, visited);
				ans += componentSize;
			}
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
		vector<vector<int>> stones(n, vector<int>(2));
		for (int i = 0; i < n; ++i) {
			cin >> stones[i][0] >> stones[i][1];
		}

		Solution solution;
		cout << solution.removeStones(stones) << endl;
	}

	return 0;
}