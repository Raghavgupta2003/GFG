//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    static bool comp(vector<int> a, vector<int> b){
        return a[2]<b[2];  //by weight
    }
    int find(vector<int>& parent, int u){
        if(parent[u] == u) return u;
        
        return parent[u] = find(parent, parent[u]);
    }
    int kruskalsMST(int n, vector<vector<int>> &edges) {
        // code here
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i=0; i<n; i++){
            parent[i] = i; //initially every node is parent of itself
        }
        
        //sort according to weight
        sort(edges.begin(), edges.end(), comp);
        int sum =0;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            int pu = find(parent, u);
            int pv = find(parent, v);
            
            if(pu == pv) continue;
            
            sum+=w; //minimum spanning tree
            
            if(rank[pu] < rank[pv]){
                //pv is parent
                parent[pu] = pv;
            }
            else if(rank[pv] < rank[pu]){
                //pu is parent
                parent[pv] = pu;
            }
            else if(rank[pv] == rank[pu]){
                //pu is parent
                parent[pv] = pu;
                rank[pu]++; //rank of parent increases
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
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        Solution obj;
        cout << obj.kruskalsMST(V, edges) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends