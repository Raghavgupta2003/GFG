//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        map<char, int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]] = i;
            //it will store last index of each element
        }

        vector<int> v;
        for(int i=0; i<s.size(); i++){
            int lastIdx = m[s[i]];
            string str = "";
            for(int j=i; j<=lastIdx; j++){
            // if any characters lastindex greater then we update lastIdx. 
                if(m[s[j]] > lastIdx) lastIdx = m[s[j]];
                str += s[j];
            }
            // cout<<str<<" ";
            v.push_back(str.size());
            i += str.size()-1;  // updating i so it will start after finishing of previous string.
        }
        return v.size();
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends