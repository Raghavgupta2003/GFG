//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }
        // If the total sum is odd, partitioning is not possible
        if (totalSum % 2 != 0) {
            return false;
        }
    
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: sum 0 is always possible
    
        // Update dp array for each element
        for (int num : arr) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
    
        return dp[target];
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