//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   public:
//     bool isLIS(vector<int> v){
//          if (v.size() < 2) return true; 
//         for(int i=0; i<v.size()-1; i++){
//             if(v[i]>v[i+1]) return false;
            
//         }
//         return true;
//     }
//     void subseq(int idx, vector<int>& arr,vector<int> &v, int &ans){
//         if(idx>=arr.size()){
//             int n = v.size();
//             if(isLIS(v)) ans = max(ans, n);
//             return;
//         }
//         //pick
//         v.push_back(arr[idx]);
//         subseq(idx+1, arr, v,ans);
//         v.pop_back();
        
//         //not pick
//         subseq(idx+1, arr, v,ans);
//     }
//     int lis(vector<int>& arr) {
//         // code here
//         vector<int> v;
//         int ans = 0;
//         subseq(0,arr,v,ans);
//         return ans;
//     }
// };

class Solution {
  public:
    int subseq(int idx,int prev, vector<int>& arr, vector<vector<int>> &dp){
        if(idx>=arr.size()){
            // return size;
            return 0;
        }
        
        //pick
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int pick = 0;
        if(prev == -1 || arr[prev]<arr[idx]){
            pick = 1 +  subseq(idx+1,idx, arr,dp);
        }
        //not pick
        int notpick = 0 + subseq(idx+1,prev, arr,dp);
        
        return dp[idx][prev+1] = max(pick, notpick);
    }
    int lis(vector<int>& arr) {
        // code here
        vector<vector<int>> dp(arr.size(), vector<int> (arr.size()+1, -1));
        
        return subseq(0,-1,arr,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends