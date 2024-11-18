//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        //finding pivot index
        int pivot = -1;
        for(int i = arr.size()-2; i>=0; i--){
            if(arr[i]<arr[i+1]){
                pivot = i;
                break;
            }
        }
        // cout<<pivot<<endl;
        if(pivot == -1){
            sort(arr.begin(),arr.end());
            return;
        }
        //reverse elements next to pivot
        reverse(arr.begin()+pivot+1, arr.end());
        //replace pivot index with next greater
        int nextgreater = -1;
        for(int i=pivot+1;i<arr.size();i++){
            if(arr[i]>arr[pivot]){
                nextgreater = i;
                break;
            }
        }
        
        swap(arr[pivot], arr[nextgreater]);
        
        
        
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends