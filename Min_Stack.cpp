#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> minElementsStack;
    stack<int> s;

public:
    MinStack() {

    }

    void push(int val) {
        s.push(val);
        if (minElementsStack.empty() || val < minElementsStack.top()) minElementsStack.push(val);
    }

    void pop() {
        int val = s.top();
        s.pop();
        if (minElementsStack.top() == val) minElementsStack.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minElementsStack.top();
    }
};


int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}