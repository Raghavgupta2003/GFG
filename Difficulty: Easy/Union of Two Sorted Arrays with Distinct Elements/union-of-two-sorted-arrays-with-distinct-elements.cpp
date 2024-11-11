//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        
        
// APPROACH 1
// USING SET

    //     set<int> s;
    //     for(int i=0;i<a.size();i++){
    //         s.insert(a[i]);
    //     }
    //     for(int i=0;i<b.size();i++){
    //         s.insert(b[i]);
    //     }
    //     vector<int> ans;
    //     ans.assign(s.begin(),s.end());
    //     return ans;
    
// APRROACH 2
// USING TWO POINTERS


    int i=0;
    int j=0;
    vector<int> v;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            if(v.size()==0 || v.back()!=a[i])
            v.push_back(a[i]);
            i++;
        }
        else{
            if(v.size()==0 || v.back()!=b[j])
            v.push_back(b[j]);
            j++;
        }
    }
    
    if(i<a.size()){
      for(int k = i;k<a.size();k++){
          if(v.size()==0 || v.back()!=a[k])
          v.push_back(a[k]);
      }
    }
    if(j<b.size()){
        for(int k = j;k<b.size();k++){
          if(v.size()==0 || v.back()!=b[k])
          v.push_back(b[k]);
      }
    }
    
    return v;





















}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends