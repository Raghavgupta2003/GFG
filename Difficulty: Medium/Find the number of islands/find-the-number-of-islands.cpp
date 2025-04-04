//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int i, int j, vector<int> delrow, vector<int> delcol, vector<vector<char>>& grid){
        
        grid[i][j] = 'W';
        
        for(int k=0; k<8; k++){
            int nrow = i+delrow[k];
            int ncol = j+delcol[k];
            
            if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size()){
                if(grid[nrow][ncol] == 'L'){
                    dfs(nrow, ncol, delrow, delcol, grid);
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        //8 direction travel
        vector<int> delrow = {0, 1, 0, -1, -1, -1, 1, 1};
        vector<int> delcol = {1, 0, -1, 0, -1, 1, 1, -1};
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 'L'){
                    dfs(i, j, delrow, delcol, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends