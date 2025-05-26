class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        int sum = 0;
        for(int i=0; i<s.size(); i++){
            string str="";
            for(int j=i; j<s.size(); j++){
                str+=s[j];
                // cout<<str<<" "<<endl;
                sum += stoi(str);
            }
        }
        
        return sum;
    }
};