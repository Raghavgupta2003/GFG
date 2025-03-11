//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int help(int idx, vector<int>& dp){
        if(idx == 0) return 1;
        if(idx == 1) return 1;
        
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = help(idx-1, dp) + help(idx-2, dp);
    }
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, -1);
        return help(n, dp);
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends