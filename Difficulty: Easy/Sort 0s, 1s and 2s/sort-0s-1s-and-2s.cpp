//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n= arr.size();
        
        int n0 = 0;
        int n1 =0;
        int n2 =0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) n0++;
            if(arr[i]==1) n1++;
            if(arr[i]==2) n2++;
        }
        
        int i=0;
        while(n0>0){
            arr[i]=0;
            n0--;
            i++;
        }
        while(n1>0){
            arr[i]=1;
            n1--;
            i++;
        }
        while(n2>0){
            arr[i]=2;
            n2--;
            i++;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends