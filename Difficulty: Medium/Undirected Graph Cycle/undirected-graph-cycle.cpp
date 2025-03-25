//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool cycle(int node, vector<vector<int>>& adj, vector<int>& visited){
        queue<pair<int, int>> q; //{node, parent}
        q.push({node, -1});
        visited[node] = 1;
        
        while(q.size()>0){
            int ele = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto it : adj[ele]){
                if(!visited[it]){
                    q.push({it, ele});
                    visited[it] = 1;
                }
                else{
                    if(it != parent) return true;
                    // "it" can only be visited when "it" is parent
                    // if "it" visited and not parent means there is cycle;
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        
        int n = adj.size(); //node+1
        vector<int> visited(n, 0);
        
        // checking for all components
        for(int i=0; i<visited.size(); i++){
            if(!visited[i]){
                if(cycle(i, adj, visited)) return true;
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends