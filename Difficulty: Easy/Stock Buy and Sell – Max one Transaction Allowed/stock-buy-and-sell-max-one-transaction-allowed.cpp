//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
//--------------TIME LIMIT EXCEEDED---------------------        
        
        // int max = 0;
        // for(int i=0;i<prices.size();i++){
        //     int currmax = prices[i];
        //     for(int j=i+1;j<prices.size();j++){
        //         if(prices[j]>=currmax) currmax = prices[j];
        //         // cout<<currmax<<endl;
        //     }
        //     int profit = currmax - prices[i];
        //     if(profit>=max) max = profit;
        // }
        
        // return max;
        
        
//--------------OTIMIZED CODE----------------------

        // we calculate minimum element and at each iteration we calculate
        //profit by (prices[i]-min)
        
        int max = 0;
        int min = INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<=min) min = prices[i];
            
            //calculating profit at each iteration
            
            int profit = prices[i]-min;
            
            //finding for max profit
            
            if(profit>=max) max = profit;
        }
        
        return max;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends