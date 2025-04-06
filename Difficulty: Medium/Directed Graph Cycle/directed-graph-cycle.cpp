//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node,  vector<int>& visited,  vector<int>& pathvisited, vector<vector<int>>& adj){
        
        visited[node] = 1;
        pathvisited[node] = 1; 
        
        for(auto it : adj[node]){
            if(!visited[it]){
                if(dfs(it, visited, pathvisited, adj)) return true;
            }
            else{
                //already visited
                //check is already pathvisited..?
                if(pathvisited[it] == 1) return true;
            }
        }
        
        pathvisited[node] = 0; //unmarking path while return back
        
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int n = V; // number of nodes
        
        vector<vector<int>> adj(n, vector<int>(0));
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b); //directed graph
        }
        
        vector<int> visited(n, 0);
         vector<int> pathvisited(n, 0);
        
        for(int i=0; i<n ; i++){
            if(!visited[i]){
                if((dfs(i, visited, pathvisited, adj))) return true;
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends