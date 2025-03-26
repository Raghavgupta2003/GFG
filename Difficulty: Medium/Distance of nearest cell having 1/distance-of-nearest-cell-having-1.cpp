//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int> (n, 0));
        
        vector<vector<int>> distance(m, vector<int> (n, 0));
        
        queue<pair<pair<int,int>, int>> q; //{i, j, distance}
        
        //pushing all ones in queue with their minimum distance
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({{i,j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        
        vector<int> delrow = {0, 1, 0, -1};
        vector<int> delcol = {1, 0, -1, 0};
        
        while(q.size()>0){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            
            distance[r][c] = t;
            
            q.pop();
            
            for(int k=0; k<4; k++){
                int nrow = r + delrow[k];
                int ncol = c + delcol[k];
                
                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol <n){
                    if(!visited[nrow][ncol]){
                        q.push({{nrow, ncol}, t+1});
                        visited[nrow][ncol] = 1;
                    }
                }
            }
        }
        
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends