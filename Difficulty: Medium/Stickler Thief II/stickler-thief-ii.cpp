//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int idx, vector<int>& arr, vector<int>& dp){
        if(idx<0) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        int pick = arr[idx] + helper(idx-2, arr, dp);
        int notpick = 0 + helper(idx-1, arr, dp);
        
        return dp[idx] = max(pick, notpick);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        vector<int> arr1(arr.begin(), arr.end()-1);
        vector<int> arr2(arr.begin()+1, arr.end());
        int n1 = arr1.size();
        int n2 = arr2.size();
        vector<int> dp1(n1, -1);
        vector<int> dp2(n2, -1);
        return max(helper(n1-1, arr1, dp1), helper(n2-1, arr2, dp2));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends