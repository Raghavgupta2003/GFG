//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V, vector<pair<int,int>>(0));
        
        for(int i=0; i<edges.size(); i++){
            int a =edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        
        //distance vector initialize with infinity
        
        vector<int> distance(V, 1e9);
        
        //declaring minheap
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0, src});
        distance[src] = 0;
        
        //BFS
        while(pq.size() > 0){
            int dist = pq.top().first;  //in pq, front() not works
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto it: adj[node]){
                int newdist = it.second + dist;
                
                if(distance[it.first] > newdist){
                    distance[it.first] = newdist;
                    pq.push({newdist, it.first});
                }
            }
        }
        
        //if any node is unreachable
        for(int i=0; i<V; i++){
            if(distance[i] == 1e9){
                distance[i] = -1;
            }
        }
        
        return distance;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends