//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};
    
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        if(grid[i][j] == 0) return;
        
        visited[i][j] = 1;
        
        //iterating in for direction;
        for(int k=0; k<4; k++){
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            
            if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size()){
                if(!visited[nrow][ncol]) dfs(nrow, ncol, grid, visited);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        // iterating first row and last col
        for(int j=0; j<n; j++){
            if(grid[0][j] == 1 && !visited[0][j]) dfs(0, j, grid, visited);
            if(grid[m-1][j] == 1 && !visited[m-1][j]) dfs(m-1, j, grid, visited);
        }
        
        //iterating first col and last col
        for(int i=0; i<m; i++){
            if(grid[i][0] == 1 && !visited[i][0]) dfs(i, 0, grid, visited);
            if(grid[i][n-1] == 1 && !visited[i][n-1]) dfs(i, n-1, grid, visited);
        }
        
        //chrcking remaining land which are not mark in visited
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1) cnt++;
            }
        }
        
        return cnt;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends