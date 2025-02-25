//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string removeConsecutiveCharacter(string& str) {
        // code here.
        set<char> s;
        string ans = "";
        for(int i=0; i<str.size(); i++){
            if(s.find(str[i]) == s.end()){
                s.clear();
                s.insert(str[i]);
                ans += str[i];

            }
            else{
                 s.insert(str[i]);
            }
            
        }
        return ans;
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
        cout << ob.removeConsecutiveCharacter(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends