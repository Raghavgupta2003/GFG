//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        // we are given a adj list in which vector<vector<int>> are stored
        vector<int> visited(V, 0);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0}); //{weight, node}
        // visited[0] = 1;
        
        int sum = 0;
        while(pq.size() > 0){
            int w = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            if(visited[node] == 1) continue;
            visited[node] = 1;
            sum += w; //mentioning into prim
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int adjwt = it[1];
                
                if(!visited[adjNode]){
                    pq.push({adjwt, adjNode});
                }
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends