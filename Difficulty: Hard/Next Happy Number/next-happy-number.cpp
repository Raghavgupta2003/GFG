//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool Happy(int N){
        // code here
        set<int> s;
        while(N>1){
            int sum = 0;
            while(N>0){
                sum += (N%10)*(N%10);
                N/=10;
            }
            if(s.find(sum)!=s.end()) break;
            s.insert(sum);
            
            N=sum;
        }
        if(N==1) return true;
        else return false;
    }
    int nextHappy(int N){
        // return Happy(10);
        
        while(true){
            N++;
            if(Happy(N)){
                return N;
            }
          
        }
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
        cout << ob.nextHappy(N) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends