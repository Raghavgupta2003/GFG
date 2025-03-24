//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<vector<int>>& adj,  vector<int> &ans, vector<int>& visited){
            
        visited[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, adj, ans, visited);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size(); //nodes+1
        vector<int> ans;
        vector<int> visited(n, 0);
       
        dfs(0, adj, ans, visited); // starting from node 0;
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends