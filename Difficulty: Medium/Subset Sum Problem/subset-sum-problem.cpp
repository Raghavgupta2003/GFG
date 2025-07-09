class Solution {
  public:
    bool ans(int i, vector<int>& arr, int sum, vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(i == 0) return arr[0] == sum;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        bool pick = false;
        if(sum >= arr[i]) pick = ans(i-1, arr, sum-arr[i], dp);
        
        bool notpick = ans(i-1, arr, sum, dp);
        
        return dp[i][sum] =  pick || notpick;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        
        return ans(n-1, arr, sum , dp);
        
    }
};