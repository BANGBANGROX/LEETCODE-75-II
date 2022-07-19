#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
	bool intersect(vector<int>& a, vector<int>& b) {
		int m = a.size();
		int n = b.size();
		int i = 0;
		int j = 0;

		while (i < m && j < n) {
			if (a[i] == b[j]) return true;
			if (a[i] < b[j]) ++i;
			else ++j;
		}

		return false;
	}

public:
	int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
		if (source == target) return 0;

		int n = routes.size();
		vector<vector<int>> graph(n);
		unordered_set<int> visited;
		unordered_set<int> targets;
		queue<pair<int, int>> q;

		for (int i = 0; i < n; ++i) {
			sort(routes.begin(), routes.end());
		}

		for (int i = 0; i < n; ++i) {
			if (binary_search(routes[i].begin(), routes[i].end(), source)) {
				visited.insert(i);
				q.push({ i,0 });
			}
			if (binary_search(routes[i].begin(), routes[i].end(), target)) {
				targets.insert(i);
			}
			for (int j = i + 1; j < n; ++j) {
				if (intersect(routes[i], routes[j])) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		while (!q.empty()) {
			pair<int, int> current = q.front();
			q.pop();
			int node = current.first;
			int depth = current.second;
			if (targets.find(node) != targets.end()) return depth + 1;
			for (int child : graph[node]) {
				if (visited.find(child) == visited.end()) {
					q.push({ child,depth + 1 });
					visited.insert(child);
				}
			}
		}

		return -1;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> routes(n);
		for (int i = 0; i < n; ++i) {
			int m;
			cin >> m;
			routes[i] = vector<int>(m);
			for (int j = 0; j < m; ++j) {
				cin >> routes[i][j];
			}
		}
		int source, target;
		cin >> source >> target;
	}

	return 0;
}