#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> count(26);
		int ans = tasks.size();

		for (char ch : tasks) {
			++count[ch - 'A'];
		}

		sort(count.begin(), count.end(), greater<int>());

		int slotTime = count[0] - 1;
		int idleTime = slotTime * n;

		for (int i = 1; i < 26; ++i) {
			idleTime -= min(slotTime, count[i]);
		}

		ans += max(0, idleTime);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int len;
		cin >> len;
		vector<char> tasks(len);
		for (char& ch : tasks) cin >> ch;
		int n;
		cin >> n;

		Solution solution;
		cout << solution.leastInterval(tasks, n);
	}

	return 0;
}