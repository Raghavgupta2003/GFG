//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int m = mat.size();
        int n = mat[0].size();
        
        //we use BFS 
        //first store rotten oranges
        //and LEVEL is time.
        
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 2){
                    q.push({{i,j}, 0});
                }
            }
        }
        //Arrays to iterate in all 4 directions
        vector<int> delrow = {1, 0, -1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        //BFS
        int tmax = 0;
        while(q.size() > 0){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            
            q.pop();
            tmax = max(t, tmax);
            
            for(int k=0; k<4; k++){
                int nrow = i + delrow[k];
                int ncol = j + delcol[k];
                
                if(nrow >=0 && ncol >= 0 && nrow < m && ncol <n){
                    if(mat[nrow][ncol] == 1){
                        //fresh orange found, we rotten them and update t to t+1
                        //and push in queue
                        mat[nrow][ncol] = 2;
                        q.push({{nrow, ncol}, t+1});
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1) return -1;
            }
        }
        return tmax;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends