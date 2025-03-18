//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
   // coded as unbounded knapsack
    int helper(int idx, int target, vector<int> &price, vector<int> &wt, vector<vector<int>>& dp){
        if(idx == 0){
            return (target/wt[idx]) * price[idx];
            // if target == 0; about condition automatically return 0;
        }
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int pick = 0;
        if(target >= wt[idx]) pick = price[idx] + helper(idx, target-wt[idx], price, wt, dp);
        
        int notpick = 0 + helper(idx-1, target, price, wt, dp);
        
        return dp[idx][target] = max(pick, notpick);
    }
    int cutRod(vector<int> &price) {
        // code here
        int target = price.size();
        int n = price.size();
        
        vector<int> wt;
        for(int i=1; i<=n; i++){
            wt.push_back(i);
        }
        
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        
        return helper(n-1, target, price,wt, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends