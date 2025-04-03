//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
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
        
        vector<int> indegree(n);
        for(int i=0; i<n; i++){
           for(auto it : adj[i]){
               indegree[it]++;
           }
        }
        
        // for(int i=0; i<indegree.size(); i++){
        //   cout<<indegree[i]<<" ";
        // }
        queue<int> q;
        vector<int> toposort;
        // pushing to queue which has indegree 0;
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        //BFS
        while(q.size() > 0){
            int node = q.front();
            q.pop();
            toposort.push_back(node);
            
            //node is in your toposort
            //remove its indegree
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return toposort;
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