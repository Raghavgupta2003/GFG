//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        vector<int> v(26,0);
        for(int i=0;i<arr.size();i++){
            v[arr[i]-97]++;
        }
        string str = "";
        for(int i=0;i<26;i++){
            if(v[i]!=0){
                for(int j=0;j<v[i];j++){
                    str+=(i+97);
                }
            }
        }
        
        return str;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends