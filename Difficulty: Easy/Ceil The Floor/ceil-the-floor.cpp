//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template


class Solution {
  public:
    vector<int> getFloorAndCeil(int target, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int lo = 0;
        int hi = arr.size()-1;
        while(lo<=hi){
            int mid = (lo + hi)/2;
            if(arr[mid] == target) return {arr[mid], arr[mid]};
            if(arr[mid] < target) lo = mid  + 1;
            if(arr[mid] > target) hi = mid -1; 
        }

        if(lo > arr.size()-1) return {arr[hi],-1};
        if(hi < 0) return {-1, arr[lo]};
        return {arr[hi],arr[lo]};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends