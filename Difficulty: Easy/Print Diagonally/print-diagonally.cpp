//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
	    vector<int> v;
		int m= A.size();
		int n= A[0].size();
	    int row=0;
	    int col=0;
        for(int i=0;i<n;i++){
            row=0;
            col=i;
		    while(row<m-1 && col>0){
		        v.push_back(A[row][col]);
		        row++;
		        col--;
		    }
		    v.push_back(A[row][col]);
        }
        
        // cout<<"row"<<row<<endl;
        // cout<<"col"<<col<<endl;
        
      
        
        for(int i=1;i<n;i++){
            row=i;
            col=n-1;
            while(col>0 && row<m-1){
		        v.push_back(A[row][col]);
		        row++;
		        col--;
		    }
		    v.push_back(A[row][col]);
        }
		    
		
		return v;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends