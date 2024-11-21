//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int p = 0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]<prices[i+1])  p+=(prices[i+1] - prices[i]);
        }
        
        return p;
        
        
        // Input: prices[] = [100, 180, 260, 310, 40, 535, 695]
        // Output: 865
        // Explanation:310 – 100 = 210 and 695 – 40 = 655. Maximum Profit = 210 + 655 = 865.
        
        // Instead of doing above we solve like
        // (180-100) + (260-180) + (310-260) = 210
        // (535-40) + (695-535) = 655
        // then max profit = 210 + 655
        
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
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends