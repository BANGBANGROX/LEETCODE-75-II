//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    vector<int> findSubarray(int a[], int n) {
        // code here
        long maxSum = INT_MIN;
        int finalStart = 0;
        int finalEnd = 0;
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (a[i] < 0) continue;
            int start = i;
            long currentSum = 0;
            while (i < n && a[i] >= 0) {
                currentSum += a[i];
                ++i;
            }
            int end = i - 1;
            if ((maxSum < currentSum) || (maxSum == currentSum && (end - start + 1) > 
                (finalEnd - finalStart + 1))) {
                maxSum = currentSum;
                finalStart = start;
                finalEnd = end;
            }
        }

        if (maxSum < 0) return { -1 };

        for (int i = finalStart; i <= finalEnd; ++i) {
            ans.push_back(a[i]);
        }

        return ans;
    }
};

//{ Driver Code Starts.

void printAns(vector<int>& ans) {
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int* a = new int[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends