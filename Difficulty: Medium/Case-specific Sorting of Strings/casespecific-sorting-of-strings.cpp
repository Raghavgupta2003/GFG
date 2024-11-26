//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<char> Upper;
        vector<char> Lower;
        for(int i=0;i<str.length();i++){
            if(str[i]>='A' && str[i]<='Z') Upper.push_back(str[i]);
            else Lower.push_back(str[i]);
        }
        
        sort(Upper.begin(),Upper.end());
        sort(Lower.begin(),Lower.end());
        
        int k=0;
        int j=0;
        for(int i=0;i<str.length();i++){
            if(str[i]>='A' && str[i]<='Z'){
                str[i] = Upper[k];
                k++;
            }
            else{
                str[i] = Lower[j];
                j++;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends