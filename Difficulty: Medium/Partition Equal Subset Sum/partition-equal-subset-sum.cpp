//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool helper(int idx, vector<int>& arr, int target, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx == 0) return (arr[idx] == target);
        
        
        if(dp[idx][target] != -1) return dp[idx][target];
        bool pick = false;
        if(arr[idx] <= target) pick =  helper(idx-1, arr, target-arr[idx], dp);
        
        bool notpick = helper(idx-1, arr, target, dp);
        
        return dp[idx][target] = pick || notpick;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int target = 0;
        for(int i=0; i<arr.size(); i++){
            target+= arr[i];
        }
        if(target % 2!=0) return false;
        target = target/2;
        
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return helper(n-1, arr, target, dp);
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends