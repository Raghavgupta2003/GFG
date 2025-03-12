//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int idx, int target, vector<int>& arr, vector<vector<int>> &dp){
        // if(target == 0) return 1;
        // if(idx == 0 ) return (target == arr[0]);
        if(idx == 0) {
            if(target == 0 && arr[0] == 0) return 2; // Two ways to make sum 0 with one 0 (pick or not pick)
            return (target == arr[0]) + (target == 0);
        }

        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int pick = 0;
        if(arr[idx] <= target) pick = helper(idx-1, target-arr[idx], arr, dp);
        int notpick = helper(idx-1, target, arr, dp);
        
        return dp[idx][target] = pick + notpick;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here]
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return helper(n-1, target, arr, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends