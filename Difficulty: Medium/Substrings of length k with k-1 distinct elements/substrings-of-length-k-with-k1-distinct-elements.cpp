class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int i=0;
        int j=0;
        int cnt = 0;
        unordered_map<int, int> m;
        while(i<s.size()){
            m[s[i]]++;
            
            while(i-j+1 > k){
                m[s[j]]--;
                if(m[s[j]] == 0) m.erase(s[j]);
                j++;
            }
            
            if(i-j+1 == k && m.size() == k-1) cnt ++;
            i++;
        }
        return cnt;
    }
};