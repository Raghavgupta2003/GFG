//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> v;
    void dec(int N){
        v.push_back(N);
        if(N<=0) return;
        dec(N-5);
    }
    void inc(int N,int tar){
        if(N>=tar) return;
        v.push_back(N+5);
        inc(N+5,tar);
    }
    vector<int> pattern(int N){
        
       if(N==0) return {0};
       dec(N);
       inc(v[v.size()-1],N);
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