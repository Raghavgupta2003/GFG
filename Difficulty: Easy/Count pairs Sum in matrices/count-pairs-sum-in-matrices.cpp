class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        unordered_map<int, int> m;
        int n = mat1.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                m[mat1[i][j]]++;
            }
        }
        
        int cnt = 0;
        
         for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int res = x - mat2[i][j];
                if(m.find(res)!= m.end() && m[res] > 0){
                    cnt++;
                    m[res]--;
                }
            }
        }
        
       return cnt;
    }
};