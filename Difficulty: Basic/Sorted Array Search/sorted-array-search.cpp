//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // k: element to be searched
    bool searchInSorted(vector<int>& arr, int k) {

        // Your code here
        int low = 0;
        int high = arr.size()-1;
        
        while(low<=high){
            int mid = low + ((high - low)/2);
            
            if(arr[mid] == k){
                return true;
            }
            else if(arr[mid]<k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main(void) {

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

        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << (ob.searchInSorted(arr, k) ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends