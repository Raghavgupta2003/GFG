//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle(int node, int parent, vector<vector<int>>& adj, vector<int>& visited){
        
        visited[node] = 1;
        
        for(auto it: adj[node]){
            if(!visited[it]){
                bool x = cycle(it, node, adj, visited);
                if(x == true) return true;
                visited[it] = 1;
            }
            else{
                if(it != parent) return true;
            }
        }
        
        return false;
        
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        
        int n = adj.size(); //node+1
        vector<int> visited(n, 0);
        
        // checking for all components
        for(int i=0; i<visited.size(); i++){
            if(!visited[i]){
                if(cycle(i, -1, adj, visited)) return true;
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends