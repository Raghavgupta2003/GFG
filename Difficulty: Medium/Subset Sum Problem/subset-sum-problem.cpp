//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool isexist(int idx, vector<int>& arr, int target, vector<vector<int>>& dp){
       
        if(target == 0) return true;
         if(idx<0) return false;
        //  if(idx == 0) return arr[idx] == target;
        
        if(dp[idx][target]!= -1) return dp[idx][target];
        bool pick = false;
        if(arr[idx]<=target) pick = isexist(idx-1, arr, target-arr[idx], dp);
        
        bool notpick = isexist(idx-1, arr, target, dp);
        
        return dp[idx][target] = (pick || notpick);
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int idx = n-1;
        // vector<vector<int>> dp(200+1, vector<int>(4*10000 + 1, -1));
         vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return isexist(idx, arr, target, dp);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends