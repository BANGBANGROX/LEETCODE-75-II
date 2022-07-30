#include<bits/stdc++.h>
using namespace std;

class Solution {
	void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
		visited[node] = true;

		for (int i = 0; i < (int)graph[node].size(); ++i) {
			if (graph[node][i] == 1 && !visited[i]) dfs(i, graph, visited);
		}
	}

public:
	int findCircleNum(vector<vector<int>>& graph) {
		int ans = 0;
		int n = graph.size();
		vector<bool> visited(n);
		
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				++ans;
				dfs(i, graph, visited);
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
		vector<vector<int>> graph(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> graph[i][j];
			}
		}

		Solution solution;
		cout << solution.findCircleNum(graph);
	}

	return 0;
}