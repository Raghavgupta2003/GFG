//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   public:
//     vector<int> maxOfSubarrays(vector<int>& arr, int k) {
//         // code here
//         vector<int> ans;
//         for(int i=0; i<arr.size()-k+1; i++){
//             int maxi = 0;
//             for(int j=i; j<i+k; j++){
//                 if(arr[j] >= maxi) maxi = arr[j];
//             }
//             ans.push_back(maxi);
//         }
//         return ans;
//     }
// };

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> ans;
        int maxi = INT_MIN;
        for(int i=0; i<k; i++){
            if(arr[i] >= maxi) maxi = arr[i];
        }
        ans.push_back(maxi);
        int i=1;
        int j=k;
        while(j<arr.size()){
            if(arr[i-1]!=maxi){
                maxi = max(arr[j], maxi);
                ans.push_back(maxi);
            }
            else{
                maxi = INT_MIN;
                for(int x = i; x<i+k; x++){
                     if(arr[x] >= maxi) maxi = arr[x];
                }
                ans.push_back(maxi);
            }
            i++;
            j++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends