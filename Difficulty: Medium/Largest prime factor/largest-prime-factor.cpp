//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        int max = INT_MIN;
        for(int i=2;i*i<=N;i++){
            while(N%i == 0){
                N/=i;
                max = i;
            }
            if(N>1)max=N;
        }
        return max;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends