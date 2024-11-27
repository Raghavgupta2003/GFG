//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        
        // if(n==r || r==0) return 1; //nCn = nC0 = 1
        // return nCr(n-1,r-1) + nCr(n-1,r);
        if(r>n) return 0;
        int dp[n+1][r+1];
        for(int i=0;i<=n;i++){
            for(int j=0 ; j<=min(i,r) ; j++){
                if(j==0 || j==i) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
        return dp[n][r];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends