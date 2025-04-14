//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int,int>>(0));
                                        //n+1 becase it one based
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        
        // printing
        //  for(int i=0; i<adj.size(); i++){
        //     for(int j=0; j<adj[i].size(); j++){
        //         cout<<"{"<<adj[i][j].first<<","<<adj[i][j].second<<"}"<<" ";
        //     }
        //     cout<<endl;
        // }
        
        //similar to dijkstra, only maintain parent array to track from where coming from
        vector<int> parent(n+1);
        // initially each node is parent of itself
        for(int i=1; i<parent.size(); i++){
            parent[i] = i;
        }
        
        vector<int> distance(n+1, 1e9); //n+1
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 1}); //{distance, src}
        distance[1] = 0;
        
        while(pq.size() > 0){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjDist = it.second;
                
                int newdist = dist + adjDist;
                
                if(distance[adjNode] > newdist){
                    distance[adjNode] = newdist;
                    pq.push({newdist, adjNode});
                    parent[adjNode] = node; //remember from where coming
                }
            }
        }
        
        //check if n is reachable or node
        if(distance[n] == 1e9) return {-1};
        
        vector<int> path;
        
        while(parent[n] != n){  //till node = source 
            path.push_back(n);
            n = parent[n];
        }
        path.push_back(n);
        reverse(path.begin(), path.end());
        // for(int i=0; i<path.size(); i++){
        //     cout<<path[i]<<" ";
        // }
        path.insert(path.begin(), distance[path.back()]);
        return path;
        
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends