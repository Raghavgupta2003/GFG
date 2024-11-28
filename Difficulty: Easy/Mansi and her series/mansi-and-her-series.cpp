//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    
    bool isprime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
     int nthprime(int n){
        // code here
        int x=2;
        int num = 1;
       while(true){
           if(isprime(x)){
                 if(num==n) return x;
               num++;
             
           }
           x++;
           
       }
       
        
    }
    int nthTerm(int n){
        // code here
       
       return (nthprime(n)*n)+n;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n;
        Solution ob;
        cout<<ob.nthTerm(n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends