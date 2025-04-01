//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   void DFS(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& ans){
       
       ans.push_back(node);
       visited[node] = 1;
       
       for(auto it : adj[node]){
           if(!visited[it]){
               DFS(it, adj, visited, ans);
           }
       }
   }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size(); //number of nodes
        
        
        vector<int> visited(n, 0);
        vector<int> ans;
        DFS(0, adj, visited, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends