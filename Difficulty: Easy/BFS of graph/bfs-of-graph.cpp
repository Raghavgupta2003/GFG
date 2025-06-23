class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        int n = adj.size();
        
        vector<int> visited(n, 0);
        
        queue<int> q;
        q.push(0); //node zero
        visited[0] = 1;
        while(q.size() > 0){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]){
                if(visited[it] == 0){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        return ans;
        
    }
};