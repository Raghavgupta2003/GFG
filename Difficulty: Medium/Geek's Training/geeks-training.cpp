//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   public:
//     int geek(int day, int last, vector<vector<int>>& arr){
//         if(day >= arr.size()){
//             return 0;
//         }
//         int maxi = 0;
//         for(int i=0; i<3; i++){ // i is activity
//             if(i!=last){
//                 int merit = arr[day][i] + geek(day+1, i, arr);
                
//                 maxi = max(maxi, merit);
//             }
//         }
//         return maxi;
        
//     }
//     int maximumPoints(vector<vector<int>>& arr) {
//         // Code here
//         return geek(0, -1, arr);
//         //last has taken -1 because no activity performed before it.
//     }
// };


//-------------------------Memorization----------------------------
class Solution {
  public:
    int geek(int day, int last, vector<vector<int>>& arr, vector<vector<int>> &dp){
        if(day >= arr.size()){
            return 0;
        }
        
        if(dp[day][last]!=-1) return dp[day][last];
        int maxi = 0;
        for(int i=0; i<3; i++){ // i is activity
            if(i!=last){
                int merit = arr[day][i] + geek(day+1, i, arr, dp);
                
                maxi = max(maxi, merit);
            }
        }
        return dp[day][last] = maxi;
        
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (4, -1));
        return geek(0, 3, arr, dp);
        //last has taken -1 because no activity performed before it.
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends