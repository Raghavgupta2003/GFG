//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Checking if the answer is correct or not
bool checkOrder(vector<int>& ans, int n) {
    if (ans.size() != n) {
        return false;
    }
    for (int i = 1; i < n; i++) {
        if (i % 2 != 0) { // Odd index
            if (ans[i] < ans[i - 1]) {
                return false;
            }
        } else { // Even index
            if (ans[i] > ans[i - 1]) {
                return false;
            }
        }
    }
    return true;
}


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrangeArray(vector<int>& arr) {
        // code here
        vector<int> ans(arr.size());
        
        sort(arr.begin(),arr.end());
        
        int k =0;
        for(int i=0;i<arr.size();i+=2){
            ans[i] = arr[k];
            k++;
        }
        for(int i=1;i<arr.size();i+=2){
            ans[i] = arr[k];
            k++;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }

        Solution ob;
        vector<int> ans = ob.rearrangeArray(nums);
        bool check_ans = checkOrder(ans, nums.size());
        bool tryingToHack = false;

        // Checking if elements in the answer are the same as the input
        sort(ans.begin(), ans.end());
        sort(nums.begin(), nums.end());
        if (ans != nums) {
            tryingToHack = true;
        }

        // Output the result
        if (tryingToHack) {
            cout << "The return array elements should be the same as the input\n";
        } else if (check_ans) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends