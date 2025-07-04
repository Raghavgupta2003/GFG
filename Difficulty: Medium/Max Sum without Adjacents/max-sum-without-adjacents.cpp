// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    
    int MaxSum(int n, vector<int>& arr,  vector<int>& dp){
        if(n == 0) return arr[0];
        
        if(dp[n]!=-1) return dp[n];
        
        int pick = arr[n] + MaxSum(n-2, arr, dp);
        int notpick = 0 + MaxSum(n-1, arr, dp);
        
        return dp[n] = max(pick, notpick);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
         vector<int> dp(n, -1);
       
        return MaxSum(n-1, arr, dp);
    }
};