//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        set<string> s;
        for(int i=0; i<wordList.size(); i++){
            s.insert(wordList[i]);
        }
        
        queue<pair<string, int>> q; //{string, level};
        
        q.push({startWord, 0});
        
        while(q.size() > 0){
            string cur = q.front().first;
            int lvl = q.front().second;
            
            if(cur == targetWord) return lvl + 1;
            q.pop();
            
            for(int i=0; i<cur.size(); i++){
                char original = cur[i];
                for(int j='a'; j<='z'; j++){
                    cur[i] = j;
                    if(s.find(cur) != s.end()){
                        q.push({cur, lvl + 1});
                        s.erase(cur);
                    }
                    cur[i] = original;
                }
            }
        }
        
        return 0;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends