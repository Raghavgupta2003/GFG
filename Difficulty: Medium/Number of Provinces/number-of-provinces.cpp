//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adjlist){
        visited[node] = 1;
        
        for(auto it : adjlist[node]){
            if(!visited[it]){
                dfs(it, visited, adjlist);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> adjlist(V+1, vector<int>(0));
        //adjlist
        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj.size(); j++){
                if(i<j && adj[i][j] == 1){
                    adjlist[i+1].push_back(j+1);
                    adjlist[j+1].push_back(i+1);
                }
            }
        }
        
        //logic
        vector<int> visited(V+1, 0);
        int ans = 0;
        for(int i=1; i<visited.size(); i++){
            if(!visited[i]){
                dfs(i, visited, adjlist);
                ans++;
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends