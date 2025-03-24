//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends


class Solution {
  public:
    void dfs(int node, vector<bool>& visited, vector<int>& ans, vector<vector<int>>& adj){
        visited[node] = true;
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, visited, ans, adj);
            }
        }
    }
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(v); // Convert edge list to adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // Since it's an undirected graph
        }
        
        vector<bool> visited(v,false); // as 0 based 
  
        vector<vector<int>> answer;
        
        for(int i=0; i<visited.size(); i++){
            if(!visited[i]){
                vector<int> ans;
                dfs(i, visited, ans, adj);
                sort(ans.begin(), ans.end());
                answer.push_back(ans);
            }
        }
        return answer;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends