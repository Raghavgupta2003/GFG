//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool isHappy(int n){
        set<int> visited;
        while(n>1){
            int sum=0;
            while(n>0){
                int temp = n%10;
                sum += temp*temp;
                n/=10;
            }
            n=sum;
            if(visited.find(sum)!=visited.end()){
                break;
            }
            visited.insert(sum);
        }
        if(n==1) return true;
        else return false;
        
    }
    int nextHappy(int N){
        while(true){
            N++;
            if(isHappy(N)) return N;
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
    }
    return 0; 
}
// } Driver Code Ends