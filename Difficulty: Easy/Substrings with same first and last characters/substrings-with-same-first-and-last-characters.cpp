class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        // int cnt = 0;
        // for(int i=0; i<s.size(); i++){
        //     string str = "";
        //     for(int j=i; j<s.size(); j++){
        //         str+=s[j];
                
        //         if(str[0] == str[str.size()-1]){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        
        //------------Optimizing it------------
        
        int cnt = 0;
        cnt += s.size();
        
        unordered_map<int, int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        
        for(auto it : m){
            if(it.second > 1){
                int n = it.second;
                cnt += ((n*(n-1))/2);
            }
        }
        
        return cnt;
    }
};