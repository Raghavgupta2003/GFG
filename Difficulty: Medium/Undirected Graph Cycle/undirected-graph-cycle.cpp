//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;
        
        for(auto it: adj[node]){
            if(!visited[it]){
                if(dfs(it, node, adj, visited)) return true;
            }
            else{
                //"it" is already visited but  
                // "it" is not equal to parent
                // means cycle detecheted
                if(it != parent) return true;
            }
        }
        return false;
    }
    bool isCycle(int n, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(n, vector<int>(0));
        
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
         
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(dfs(i, -1, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends