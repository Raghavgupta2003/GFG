//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int findFloor(vector<int>& arr, int target) {

        // Your code here
        int lo = 0;
        int hi = arr.size()-1;
        while(lo<=hi){
            int mid = (lo + hi)/2;
            if(arr[mid] == target) return mid;
            if(arr[mid] < target) lo = mid  + 1;
            if(arr[mid] > target) hi = mid -1; 
        }

        return hi;
    
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, k);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends