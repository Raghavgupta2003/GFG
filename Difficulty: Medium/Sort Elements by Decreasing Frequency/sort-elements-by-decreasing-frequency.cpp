//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool comp(pair<int,int> a, pair<int,int> b){
        if(a.second!=b.second) return b.second<a.second;
        
        return a.first<b.first;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        
        vector<pair<int,int>> v;
        for(auto it : freq){
            v.push_back({it.first,it.second});
        }
        
        sort(v.begin(),v.end(),comp);
        
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].second;j++)
            ans.push_back(v[i].first);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends