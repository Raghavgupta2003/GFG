class Solution {
  public:
    bool dfs(int node, int parent,  vector<int>& visited, vector<vector<int>>& adj){
        visited[node] = 1;
        
        for(auto it: adj[node]){
            if(!visited[it]){
                bool x = dfs(it, node, visited, adj);
                if(x) return true;
            }
            else{ //already visited
                if(it != parent) return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V, vector<int>(0));
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> visited(V, 0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool x = dfs(i, -1, visited, adj);
                if(x) return true; //cycle founded
            }
        }
        
        return false;
    }
};