//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n==0) return 0;
        vector<int> dp(n,1);
        int maxlength = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i])  dp[i] = max(dp[i],dp[j]+1);
            }
            maxlength = max(maxlength,dp[i]);
        }
        
        return maxlength;
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
        cout << obj.longestSubsequence(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends