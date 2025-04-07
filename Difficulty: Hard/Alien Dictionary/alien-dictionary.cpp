//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    pair<int,int> compare(string a, string b){
        int i=0;
        int j=0;
        
        while(a[i]==b[j]){
            i++;
            j++;
        }
        
        if(i<a.size() && j<b.size()) return {a[i]-'a', b[j]-'a'};
        
        if(a.size() > b.size()) return {-2, -2};
        
        return {-1, -1};
    }
    string findOrder(vector<string> &words) {
        // code here
        // we create edges of a graph
        vector<pair<int,int>> edges;
        
        for(int i=1; i<words.size(); i++){
            pair<int, int> edge = compare(words[i-1], words[i]);
            if(edge.first == -2 && edge.second == -2) return "";
            if(edge.first != -1 && edge.second != -1) edges.push_back(edge);

            // cout<<edge.first<<" "<<edge.second<<endl;
        }
        //counting number of nodes
        set<int> s;
        for(auto it : words){
            for(auto ch : it){
                s.insert(ch-'a');
            }
        }
        vector<int> present(26, 0);
        for(auto node : s){
            present[node] = 1;
        }
        //creating adjacency list of directed graph
        // we have adj list of size 26
        // but access only those indes which are marked present in present array
        int n = 26;
        vector<vector<int>> adj(n, vector<int>(0));
        for(auto it : edges){
            int a = it.first;
            int b = it.second;
            adj[a].push_back(b);
        }
        
        //indegree
        vector<int> indegree(n, 0);
        
        for(auto it : edges){
            int a = it.first;
            int b = it.second;
            //there is edge a->b
            indegree[b]++;
        }
        
        //pushing nodes whose indegree is equal to zero
        queue<int> q;
        for(int i=0; i<n; i++){
            if(present[i] && indegree[i] == 0){
                q.push(i);
            }
        }
        
        //Applying BFS
        vector<int> toposort;
        while(q.size() > 0){
            int node = q.front();
            q.pop();
            toposort.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        if(toposort.size() != s.size()) return ""; //incosistent orderting
        
        string order = "";
        for(int i=0; i<toposort.size(); i++){
            order += (toposort[i] + 'a');
        }
        // cout<<order;
        
        return order;
        
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends