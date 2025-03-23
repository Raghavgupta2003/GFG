//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int idx, string s, vector<int>& dp){
        int n = s.size();
        if(idx >= n) return 1;
        if(s[idx] == '0') return 0;

        if(dp[idx]!=-1) return dp[idx];

        //picking one element
        int left = helper(idx+1, s, dp);
        //picking two elements
        int right = 0;
        if(idx != n-1 && (s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6'))){
            // when we took two elements then it can be '1x' where 'x' can be anything.
            // it can be '2x' where 'x'<=6 as in english only 26 alphabets there.
            right = helper(idx+2, s, dp);
        }

        return dp[idx] = left + right;
    }
    int countWays(string &digits) {
        // Code here
         int n = digits.size();
        vector<int> dp(n, -1);
        return helper(0, digits, dp);
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends