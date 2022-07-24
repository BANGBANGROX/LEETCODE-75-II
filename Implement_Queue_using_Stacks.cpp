#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {

    }

    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
            return;
        }

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s2.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) return -1;

        int ans = s1.top();
        s1.pop();

        return ans;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}