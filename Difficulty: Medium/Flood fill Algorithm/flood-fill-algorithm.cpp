//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
//                                   int newColor) {
//         // Code here
//         int m = image.size();
//         int n = image[0].size();
        
//         int prevColor = image[sr][sc];
        
//         queue<pair<int,int>> q;
//         q.push({sr, sc}); //pushing indexes from where we start 
//         image[sr][sc] = newColor; //coloring it
        
        
//         vector<int> delrow = {1, 0, -1, 0};
//         vector<int> delcol = {0, 1, 0, -1};
//         while(q.size() > 0){
//             int i = q.front().first;
//             int j = q.front().second;
            
//             q.pop();
            
//             for(int k=0; k<4; k++){
//                 int nrow = i + delrow[k];
//                 int ncol = j + delcol[k];
//                 if(nrow>=0 && ncol>=0 && nrow<m && ncol<n){
//                     if(image[nrow][ncol] == prevColor){ // if adjacent have prev color, thebn push in queue and color it with newColor.
//                         q.push({nrow, ncol});
//                         image[nrow][ncol] = newColor;
//                     }
//                 }
//             }
//         }
//         return image;
//     }
// };

class Solution {
  public:
    vector<int> delrow = {1, 0, -1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    void dfs(int i, int j, vector<vector<int>>& image, int newColor, int prevColor){
        if(image[i][j] != prevColor) return;
        
        image[i][j] = newColor;
        for(int k=0; k<4; k++){
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            if(nrow>=0 && ncol>=0 && nrow<image.size() && ncol<image[0].size()){
                dfs(nrow, ncol, image, newColor, prevColor);
            }
         }  
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int m = image.size();
        int n = image[0].size();
        
        int prevColor = image[sr][sc];
        if(newColor == prevColor) return image;
        
        dfs(sr, sc, image, newColor, prevColor);
        
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends