//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int idx, vector<int>& arr, int target, vector<vector<int>>& dp){
        if(idx >= arr.size() && target == 0) return 1;
        if(idx >= arr.size()) return 0;
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int pick = 0;
        if(arr[idx] <= target) pick = helper(idx+1, arr, target-arr[idx], dp);
        
        int notpick = helper(idx+1, arr, target, dp);
        
        return dp[idx][target] = pick + notpick;
        
    }
    int countPartitions(vector<int>& arr, int d) {
        
        
        // Code here
        int total = 0;
        int n = arr.size();
        for(int i=0; i<arr.size(); i++){
            total += arr[i];
        }

        int target = (total - d)/2;
        //basecases 
        if((total - d)%2 != 0) return 0;
        if((total-d) < 0) return 0;
        // cout<<endl<<target<<endl;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return helper(0, arr, target, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends