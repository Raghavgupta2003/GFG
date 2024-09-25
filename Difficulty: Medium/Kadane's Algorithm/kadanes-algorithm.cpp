//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        bool flag = true;
        int max = INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>0){
                flag=false;
                break;
            }
            if(arr[i]>max) max = arr[i];
            
        }
        if(flag==true) return max;
        int maxsum =0;
        int currsum = 0;
        for(int i=0;i<arr.size();i++){
            currsum+=arr[i];
            if(currsum<=0) currsum=0;
            // maxsum = max(maxsum,currsum);
            if(maxsum<currsum) maxsum=currsum;
            
        }
        
        return maxsum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends