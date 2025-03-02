//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<int> num;
        stack<string> st;
        string curnum = "";
        string curst = "";
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            
            if(isdigit(ch)){
                curnum+=ch;
                // cout<<curnum<<endl;
            }
            else if(ch == '['){
                int digit = stoi(curnum);
                // cout<<curnum<<" -num- "<<endl;
                num.push(digit);
                curnum = "";
                // cout<<curst<<" -st- "<<endl;
                st.push(curst);
                curst = "";
            }
            else if(ch == ']'){
                
                int n = num.top();
                num.pop();
                string str = st.top();
                st.pop();
                
                string ans = "";
                
                for(int i=1; i<=n; i++){
                    ans += curst;
                }
                ans = str+ans;
                curst = ans;
                // cout<<ans<<" ";
            }else{
                curst += ch;
            }
        }
        
        return curst;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends