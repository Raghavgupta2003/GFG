//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool DFS(int node, vector<vector<int>> &adj, vector<int>& visited, vector<int>& pathvisited){
        
        visited[node] = 1;
        pathvisited[node] = 1;
        
        for(auto it: adj[node]){
            if(!visited[it]){
                if(DFS(it, adj, visited, pathvisited)) return true;
            }else{ 
                //already visited but it should be on same path
                if(pathvisited[it]) return true;
            }
        }
        
        pathvisited[node] = 0;
        
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        
        int n = adj.size(); // number of nodes
        
        vector<int> visited(n, 0);
        vector<int> pathvisited(n, 0);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(DFS(i, adj, visited, pathvisited)) return true;
            }
        }
        
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends