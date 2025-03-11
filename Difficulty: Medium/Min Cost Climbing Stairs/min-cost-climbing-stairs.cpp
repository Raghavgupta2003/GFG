//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int helper(int idx, vector<int>& cost, vector<int>& dp){
        
        if(idx == cost.size()-2) return cost[idx];
        if(idx == cost.size()-1) return cost[idx];
        if(idx >= cost.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        int one = cost[idx] + helper(idx+1, cost, dp);
        int two = cost[idx] + helper(idx+2, cost, dp);
        
        return dp[idx] = min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        
        vector<int> dp(n+1, -1);
        return min(helper(0, cost, dp), helper(1, cost, dp));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends