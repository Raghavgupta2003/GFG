class Solution {
  public:
    int count(int i, vector<int> ans, int target, vector<vector<int>>& dp){
        if(i >= ans.size()){
            if(target == 0) return 1;
            return 0;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        int pick = 0;
        if(target >= ans[i]) pick = count(i+1, ans, target-ans[i], dp);
        int notpick = count(i+1, ans, target, dp);
        
        return dp[i][target] = pick + notpick;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
        return count(0,arr, target, dp);
    }
};