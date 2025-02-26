//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   public:
//     int cost(int idx, vector<int>& heights){
//         if(idx == 0) return 0;
        
//         int left = cost(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
//         int right = INT_MAX;
//         if(idx>1) right = cost(idx-2, heights) + abs(heights[idx] - heights[idx-2]); 
        
//         return min(left, right);
//     }
//     int minCost(vector<int>& height) {
//         // Code here
//         int n = height.size();
//         return cost(n-1, height);
//     }
// };

//----------memorization-----------

class Solution {
  public:
    int cost(int idx, vector<int>& heights, vector<int>& dp){
        if(idx == 0) return 0;
        
        if(dp[idx] !=-1) return dp[idx];
        int left = cost(idx-1, heights,dp) + abs(heights[idx] - heights[idx-1]);
        int right = INT_MAX;
        if(idx>1) right = cost(idx-2, heights,dp) + abs(heights[idx] - heights[idx-2]); 
        
        return dp[idx] = min(left, right);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        return cost(n-1, height, dp);
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends