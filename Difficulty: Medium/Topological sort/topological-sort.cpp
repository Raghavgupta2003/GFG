class Solution {
  public:
    bool topo(int node, vector<vector<int>>& adj, stack<int>& st, vector<int>& visited){
        visited[node] = 1;
        
        for(auto it: adj[node]){
            if(!visited[it]){
                 topo(it,adj,st, visited);
            }
        }
        
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int n = V;
        vector<vector<int>> adj(n, vector<int>(0));
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        stack<int> st;
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                topo(i,adj,st, visited);
            }
        }
        
        vector<int> toposort;
        
        while(st.size()>0){
            toposort.push_back(st.top());
            st.pop();
        }
        
        // reverse(toposort.begin(), toposort.end());
        
        return toposort;
        
    }
};