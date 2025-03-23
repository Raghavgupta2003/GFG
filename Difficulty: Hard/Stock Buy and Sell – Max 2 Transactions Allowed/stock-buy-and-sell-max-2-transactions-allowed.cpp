//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<int> lefttoright(n, 0);
        vector<int> righttoleft(n, 0);
        
        int mini = prices[0];
        for(int i=1; i<n; i++){
            if(prices[i] <= mini) mini = prices[i];
            lefttoright[i] = max(lefttoright[i-1], prices[i] - mini);
        }
        
        int maxi = prices[n-1];
        for(int i=n-2; i>=0; i--){
            if(prices[i] >= maxi) maxi = prices[i];
            righttoleft[i] =  max(righttoleft[i-1], maxi - prices[i]);;
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            ans = max(ans, lefttoright[i] + righttoleft[i]);
        }
        
        return ans;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends