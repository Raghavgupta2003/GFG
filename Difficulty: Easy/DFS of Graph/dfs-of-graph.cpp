class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited,  vector<int>& ans){
        visited[node] = 1;
        
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        // Code here
        vector<int> visited(n, 0);
        vector<int> ans;
        dfs(0, adj, visited, ans);
        
        return ans;
    }
};