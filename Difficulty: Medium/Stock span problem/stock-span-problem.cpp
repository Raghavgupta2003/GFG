//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n = arr.size();
        stack<int> st;
        vector<int> pge(n,-1);
        pge[0] = -1;
        st.push(0);
        for(int i=1; i<arr.size(); i++){
            while(st.size()>0 && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.size()!=0) pge[i] = st.top(); 
            st.push(i);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(i-pge[i]);
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends