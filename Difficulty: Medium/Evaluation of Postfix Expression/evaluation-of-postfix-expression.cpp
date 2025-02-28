//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int a, int b, string ch){
        int ans = 0;
        if(ch == "+")  ans = a+b;
        else if(ch == "-") ans = a-b;
        else if(ch == "*") ans = a*b;
        else if(ch == "/") ans = a/b;
        
        
        return ans;
    }
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        for(int i=0; i<arr.size(); i++){
            string ch = arr[i];
            
            if(ch=="*" || ch == "/" || ch == "+" || ch=="-"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                int ans = solve(a, b, ch);
                st.push(ans);
            }
            else{
                st.push(stoi(ch));
            }
        }
        
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends