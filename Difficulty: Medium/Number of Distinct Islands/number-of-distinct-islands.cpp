// User function Template for C++

class Solution {
  public:
    vector<int> delrow = {0, 1, 0, -1};
    vector<int> delcol = {1, 0, -1, 0};
    void DFS(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<pair<int, int>> &v, int r, int c){
        visited[i][j] = 1;
        
        v.push_back({r-i, c-j});
        for(int k=0; k<4; k++){
            int ir = i + delrow[k];
            int ic = j + delcol[k];

            if(ir >= 0 && ic >= 0 && ir < grid.size() && ic < grid[0].size()){
                if(grid[ir][ic] == 1 && !visited[ir][ic]){
                    DFS(ir, ic, grid, visited, v, r, c);
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<pair<int, int>>> s;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                vector<pair<int, int>> v;
                if(!visited[i][j] && grid[i][j] == 1){
                    DFS(i, j, grid, visited, v, i, j);
                    sort(v.begin(), v.end());
                    s.insert(v);
                }
            }
        }
        
        return s.size();
        
    }
};
