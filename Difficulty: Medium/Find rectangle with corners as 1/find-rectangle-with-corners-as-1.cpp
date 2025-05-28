class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        set<pair<int, int>> s;
        
        for(int i=0; i<m; i++){
            vector<int> v;
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1) v.push_back(j);
            }
            
            //valid pairs from vector v;
            for(int k=0; k<v.size(); k++){
                for(int l=k+1; l<v.size(); l++){
                    if(s.find({v[k],v[l]})!=s.end()) return true;
                    s.insert({v[k],v[l]});
                }
            }
        }
        
        return false;
    }
};