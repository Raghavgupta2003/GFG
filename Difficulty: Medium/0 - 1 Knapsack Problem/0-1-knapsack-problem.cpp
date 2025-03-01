//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int solve(int idx, int w, vector<int>& val, vector<int>& wt, vector<vector<int>> &dp){
        if(idx>= val.size()) return 0;
        if (dp[idx][w] !=-1) return dp[idx][w];
        //take
        int take = INT_MIN;
        if(w-wt[idx] >= 0){
            take = val[idx] + solve(idx+1, w-wt[idx], val, wt, dp);
        }
        int nottake = 0 + solve(idx+1, w, val, wt, dp);
        
        return dp[idx][w] = max(take, nottake);
    }
    int knapSack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (w+1, -1));
        return solve(0, w, val, wt, dp);
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
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends