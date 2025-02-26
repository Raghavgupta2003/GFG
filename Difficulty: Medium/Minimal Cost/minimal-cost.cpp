//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   public:
//     int cost(int idx, int k, vector<int>& arr){
//         if(idx == 0) return 0; // arr[0]-arr[0] = 0;
        
//         int minimum = INT_MAX;
//         for(int i=1; i<=k; i++){
           
//             if(idx-i >=0 ){
//                 int x = cost(idx-i, k, arr) + abs(arr[idx] - arr[idx-i]);
//                 minimum = min(minimum, x);
//             }
//         }
//         return minimum;
//     }
//     int minimizeCost(int k, vector<int>& arr) {
//         // Code here
//         int n = arr.size();
//         return cost(n-1, k, arr);
//     }
// };

class Solution {
  public:
    int cost(int idx, int k, vector<int>& arr,  vector<int> &dp){
        if(idx == 0) return 0; // arr[0]-arr[0] = 0;
        
        int minimum = INT_MAX;
        for(int i=1; i<=k; i++){
           
            if(idx-i >=0 ){
                if(dp[idx] != -1) return dp[idx];
                int x = cost(idx-i, k, arr,dp) + abs(arr[idx] - arr[idx-i]);
                minimum = min(minimum, x);
            }
        }
        return dp[idx] = minimum;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return cost(n-1, k, arr,dp);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends