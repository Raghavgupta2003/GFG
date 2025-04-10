//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    void dfs(int node, vector<int>& visited, vector<vector<pair<int,int>>>& adj, stack<int>& st){
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it.first]){
                dfs(it.first, visited, adj, st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V, vector<pair<int,int>>(0));
        
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int weight = edges[i][2];
            adj[a].push_back({b, weight});
            // adj[b].push_back({a, weight});
        }
        
        //toposort
        vector<int> visited(V, 0);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, visited, adj, st);
            }
        }
        
    //-------------printing adj list--------------
    //   for(int i=0; i<adj.size(); i++){
    //       for(auto it : adj[i]){
    //           cout<<"{"<<it.first<<","<<it.second<<"}"<<"  ";
    //       }
    //       cout<<endl;
    //   }
    //     cout<<endl;
    //     vector<int> topo;
    //     while(st.size()>0){
    //         topo.push_back(st.top());
    //         st.pop();
    //     }
    //     return topo;
        
        vector<int> distance(V, 1e9);
        //since source is 0, distance of source from source = 0
        distance[0] = 0;
        
        while(st.size() > 0){
            int node = st.top();
            st.pop();
            
            for(auto it: adj[node]){
                int cur = it.first;
                int w = it.second;
                
                int path = distance[node] + w;
                if(distance[cur] > path) distance[cur] = path;
            }
        }
        for(int i=0; i<distance.size(); i++){
            if(distance[i] == 1e9) distance[i] = -1;
        }
        return distance;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends