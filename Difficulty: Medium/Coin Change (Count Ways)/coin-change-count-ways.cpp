//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int idx, vector<int>& coins, int sum, vector<vector<int>>& dp){
       
        if(sum == 0) return 1;
        if(idx < 0) return 0;
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int pick = 0;
        if(sum >= coins[idx]) pick = helper(idx, coins, sum-coins[idx], dp);
        
        int notpick = helper(idx-1, coins, sum, dp);
        
        return dp[idx][sum] = notpick + pick;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(n-1, coins, sum, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends