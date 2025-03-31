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
    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int, int>>& v, int base_i, int base_j){
        
        if(grid[i][j] == 1) grid[i][j] = 0;
        
        for(int k=0; k<4; k++){
            int nrow = i+delrow[k];
            int ncol = j+delcol[k];
            
            if(nrow >=0 && ncol >=0 && nrow <grid.size() && ncol <grid[0].size() && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid, v, base_i, base_j);
                v.push_back({base_i-nrow, base_j-ncol});
                // this vector is storing shape of region
                // to get shape we store cordinates by subtracting from base cordinates.
            }
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // code here
        set<vector<pair<int,int>>> s;
        // we use set data structure to store shape of region in form of vector of pairs.
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    vector<pair<int,int>> v;
                    dfs(i, j, grid, v, i, j);
                    s.insert(v);
                }
            }
        }
        
        // for(auto it : s){
        //     for(int i = 0; i< it.size(); i++){
        //         cout<<it[i].first<<" "<<it[i].second<<" / ";
        //     }
        //     cout<<endl;
        // }
        
        return s.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends