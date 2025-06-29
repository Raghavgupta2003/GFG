class Solution {
  public:
    pair<int, int> compare(string a, string b){
        int i=0;
        int j=0;
        while(a[i]==b[i]){
            i++;
            j++;
        }
        
        if(i<a.size() && j<b.size()) return {a[i]-'a', b[i]-'a'}; //valid edge
        
        if(a.size() > b.size()) return {-1, -1}; //invalid dictionary
        
        return {-2, -2}; //no edges
    }
    string findOrder(vector<string> &words) {
        // code here
        //step 1: creating directed edges from the array by comparing adjacent words
        
        vector<pair<int, int>> edges;
        for(int i=1; i<words.size(); i++){
            pair<int, int> edge = compare(words[i-1], words[i]);
            
            if(edge.first == -1 && edge.second == -1) return ""; //invalid dictionart
            
            if(edge.first != -2 && edge.second !=-2) edges.push_back(edge); //valid edge
        }
        
        int n = 26; //nodes = 26 as present in english language
        vector<int> present(n, 0); //array of present char in words
        set<char> s;
        for(auto word : words){
            for(auto ch : word){
                present[ch-'a'] = 1;
                s.insert(ch);
            }
        }
        
        //Making adjancy list of size 26
        vector<vector<int>> adj(n, vector<int>(0));
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i].first;
            int v = edges[i].second;
            // cout<<(char)(u+'a')<<" "<<(char)(v+'a')<<endl;
            
            adj[u].push_back(v);
        }
        
        //toposort
        
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++){
           for(auto it : adj[i]){
               indegree[it]++;
           }
        }
        
        queue<int> q;
        
        for(int i=0; i<n; i++){
            if(present[i]==1 && indegree[i]==0){
                q.push(i);
            }
        }
        
        string order = "";
        
        while(q.size() > 0){
            int node = q.front();
            q.pop();
            order += char(node + 'a');
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        // cout<<order<<endl;
        if(order.size() != s.size()) return ""; //incosistent orderting
        return order;
        
        
    }
};