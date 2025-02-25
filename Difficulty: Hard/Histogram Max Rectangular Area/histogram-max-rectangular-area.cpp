//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        stack<int> st;
        st.push(n-1);
        vector<int> nse(n, n);
        for(int i=n-2; i>=0; i--){
            while(st.size()>0 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.size() != 0)  nse[i] = st.top() ;
            st.push(i);
        }
        
        stack<int> s;
        s.push(0);
        vector<int> pse(n, -1);
        for(int i=1; i<n; i++){
            while(s.size()>0 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size() != 0) pse[i] = s.top();
            s.push(i);
        }
        
        // for(int i=0; i<nse.size(); i++){
        //     if(pse[i]!=-1)
        //     cout<<arr[pse[i]]<<" ";
        //     else cout<<-1<<" ";
        // }
        
        int maxi = 0;
        for(int i=0; i<n; i++){
            int area = (nse[i] - pse[i] - 1) * arr[i];
            maxi = max(maxi, area);
        }
        
        return maxi;
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends