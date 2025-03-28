//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void incdecre(int N,vector<int> &v){
        if(N<=0){
            v.push_back(N);
            return;
        }
        v.push_back(N);
        incdecre(N-5,v);
        v.push_back(N);
    }
    vector<int> pattern(int N){
       vector<int> v;
       incdecre(N,v);
       return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends