//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(st.size()>0){
                if(ch == ')' && st.top() == '(') st.pop();
                else if(ch == '}' && st.top() == '{') st.pop();
                else if(ch == ']' && st.top() == '[') st.pop();
                else st.push(ch);
            }
            else st.push(ch);
        }
        
        if(st.size() == 0) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends