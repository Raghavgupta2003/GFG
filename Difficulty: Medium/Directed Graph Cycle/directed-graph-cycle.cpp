class Solution {
  public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int>& visited, vector<int>& pathvisited){
        visited[node] = 1;
        pathvisited[node] = 1;
        
        for(auto it: adj[node]){
            if(!visited[it]){
                if(dfs(it, adj, visited, pathvisited)) return true;
            }else{
                // if visited then check if it is pathvisited too
                if(pathvisited[it]){
                    return true;
                }
            }
        }
        
        pathvisited[node] = 0; //while backtracking unmark it
        
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int n = V;
        vector<vector<int>> adj(n, vector<int>(0));
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v); //directed graph
        }
        
        
        vector<int> visited(n, 0);
        vector<int> pathvisited(n, 0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, pathvisited)) return true;
            }
        }
        
        return false;
    }
};