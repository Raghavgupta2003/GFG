//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node,  vector<int>& visited, vector<vector<int>>& adj, stack<int>& st){
        
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, visited, adj, st);
            }
        }
        
        st.push(node);
    }
    vector<int> topoSort(int n, vector<vector<int>>& edges){
        // code here
        // TOPOLOGICAL SORT ALWAYS AVAILABLE IN DIRECTED ACYCLIC GRAPH
        
        // n = numver of nodes
        vector<vector<int>> adj(n, vector<int>(0));
        
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            // adj[b].push_back(a); -> it will not be there because we have directed graph
        }
        vector<int> visited(n, 0);
        
        stack<int> st; // to store topological sort
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, adj, st);
            }
        }
        
        vector<int> ans;
        while(st.size() > 0){
            // cout<<st.top()<<" ";
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);

        cout << check(V, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends