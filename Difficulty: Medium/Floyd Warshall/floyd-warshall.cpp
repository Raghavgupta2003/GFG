//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        //we are already given with initial adj matrix
        int n = dist.size();
        for(int via = 0; via<n; via++){ //for all nodes
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if (dist[i][via] != 1e8 && dist[via][j] != 1e8)
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
            
        }
        
        //if negative weight cycle
        for(int i=0; i<n; i++){
            if(dist[i][i] < 0){
                //"Negagive"
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.floydWarshall(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends