//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        
         vector<int> v;
         int m = mat.size();
         int n= mat[0].size();
         int row=0;
         int col=0;
         int dir = 1; //bottom to up
         
         while(row<m && col<n){
             if(dir==1){
                 while(row>0 && col<n-1){
                     v.push_back(mat[row][col]);
                     row--;
                     col++;
                 }
                 v.push_back(mat[row][col]);
                 
                 if(col==n-1) row++;
                 else col++;
                 
                 dir=0;
             }
             else{
                 while(col>0 && row<m-1){
                    v.push_back(mat[row][col]);
                    row++;
                    col--;
                 }
                 v.push_back(mat[row][col]);
                 
                 if(row==m-1) col++;
                 else row++;
                 
                 dir=1;
             }
         }
         
         return v;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends