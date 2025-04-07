//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited);
            }
        }
    }
    int countConnected(int n, vector<vector<int>> &edges){
        vector<vector<int>> adj(n, vector<int>(0));
        
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int> visited(n, 0);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                cnt++;
            }
        }
        return cnt;
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        int count1 = countConnected(V, edges);
        
        vector<vector<int>> edge;
        for(int i=0; i<edges.size(); i++){
            if(!(edges[i][0] == c && edges[i][1] == d) || (edges[i][0] == d && edges[i][1] == c)){
                edge.push_back({edges[i][0], edges[i][1]});
            }
        }
        
        int count2 = countConnected(V, edge); //passing vector without c->d edge
        
        if(count2 > count1) return true;
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends