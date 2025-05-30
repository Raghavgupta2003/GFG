//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int  helper(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp){
        if(idx >= val.size()) return 0;
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int pick = 0;
        if(W >= wt[idx]) pick = val[idx] + helper(idx+1, W-wt[idx], val, wt, dp);
        int notpick = 0 + helper(idx+1, W, val, wt, dp);
        
        return dp[idx][W] = max(pick, notpick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return helper(0, W, val, wt, dp);
    }
};





//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends