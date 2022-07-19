#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses);
		vector<int> inDegree(numCourses);
		vector<int> ans;
		queue<int> q;

		for (vector<int>& prerequisite : prerequisites) {
			int u = prerequisite[0];
			int v = prerequisite[1];
			graph[v].push_back(u);
			++inDegree[u];
		}

		for (int i = 0; i < numCourses; ++i) {
			if (inDegree[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			ans.push_back(node);
			for (int child : graph[node]) {
				--inDegree[child];
				if (inDegree[child] == 0) q.push(child);
			}
		}

		if ((int)ans.size() < numCourses) ans.clear();

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int numCourses, m;
		cin >> numCourses >> m;
		vector<vector<int>> prerequisites(m, vector<int>(2));
		for (vector<int>& x : prerequisites) {
			cin >> x[0] >> x[1];
		}

		Solution solution;
		vector<int> ans = solution.findOrder(numCourses, prerequisites);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}