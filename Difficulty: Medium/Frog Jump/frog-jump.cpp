class Solution {
  public:
    int cost(int n, vector<int>& height, vector<int>& dp){
        if(n<=0) return 0; //jump from 0 to 0
        
        if(dp[n] != -1) return dp[n];
        int skip1 = abs(height[n] - height[n-1]) + cost(n-1, height, dp);
        int skip2 = 1e9;
        if(n > 1) skip2 = abs(height[n] - height[n-2]) + cost(n-2, height, dp);
        
        return dp[n] = min(skip1, skip2);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        return cost(n-1, height, dp);
    }
};