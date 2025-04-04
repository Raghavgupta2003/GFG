//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    string isCyclic(vector<vector<int>> &adj) {
        // code here
        // int n = 0; //number of nodes
        // set<int> s;
        // for(int i=0; i<edges.size(); i++){
        //     s.insert(edges[i][0]);
        //     s.insert(edges[i][1]);
        // }
        // n = s.size();
        // //adj list
        // vector<vector<int>> adj(n, vector<int> (0));
        // for(int i=0; i<edges.size(); i++){
        //     int a = edges[i][0];
        //     int b = edges[i][1];
            
        //     adj[a].push_back(b);
        // }
         
        int n = adj.size();
        // Now working on khans algorithm
        vector<int> indegree(n);
        
        for(int i=0; i<n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        //pushing element whose indegree is 0;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> toposort;
        
        //applying bfs
        while(q.size() > 0){
            int cur = q.front();
            
            q.pop();
            toposort.push_back(cur);
            
            for(auto it : adj[cur]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        // if toposort valid then no cycle
        if(toposort.size() == n) return "false";
        
        return "true";
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends