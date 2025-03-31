//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        
        int nodes = adj.size();
        //visited array
        vector<int> color(nodes, -1);
        
        queue<int> q;
        q.push(0);
        
        while(q.size() > 0){
            int cur = q.front();
            q.pop();
            
            for(auto it : adj[cur]){
                if(color[it] == -1){
                    q.push(it);
                    color[it] = !(color[cur]);
                }
                else{
                    if(color[it] == color[cur]) return false;
                }
            }
        }
        
        return true;
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
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends