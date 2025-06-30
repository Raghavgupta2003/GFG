// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        int n =V;
        vector<vector<pair<int,int>>> adj(n, vector<pair<int, int>>(0));
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
        }
        
        vector<int> distance(n, 1e9);
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        distance[0] = 0;
        
        while(q.size() > 0){
            int node = q.front().first;
            int dist = q.front().second;
            
            q.pop();
            
            for(auto it : adj[node]){
                int node = it.first;
                int weight = it.second;
                
                if(distance[node] > dist + weight){
                    distance[node] = dist + weight;
                    q.push({node, dist+weight});
                }
            }
        }
        
        for(int i=0; i<distance.size(); i++){
            if(distance[i] == 1e9) distance[i] = -1;
        }
        return distance;
        
    }
};
