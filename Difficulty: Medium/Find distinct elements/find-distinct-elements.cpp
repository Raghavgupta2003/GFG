//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int distinct(vector<vector<int>> M, int N)
    {
        // code here
        int m=M.size();
        int n=M[0].size();
        
        vector<int> v(n,1);
        
        for(int i=1;i<m;i++){
            unordered_map<int,int> m;
            for(int j=0;j<n;j++){
                m[M[i][j]]++;
            }
            for(int k=0;k<n;k++){
                if(m[M[0][k]]>0){
                    m[M[0][k]]--;
                }
                else{
                    v[k]=0;
                }
            }
        }
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     if(v[i]==1) cnt++;
        // }
        // return cnt;
        set<int> s;
        for(int i=0;i<n;i++){
            if(v[i]==1) s.insert(M[0][i]);
        }
        return s.size();
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for(int i = 0;i < N*N; i++)
            cin>>M[i/N][i%N];
        
        Solution ob;
        cout<<ob.distinct(M, N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends