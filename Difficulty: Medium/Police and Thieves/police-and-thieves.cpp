class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        vector<int> police;
        vector<int> thief;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 'P') police.push_back(i);
            else if(arr[i] == 'T') thief.push_back(i);
        }
        
        int i = 0;
        int j = 0;
        
        int ans =0;        
        while(i<police.size() && j<thief.size()){
            if(abs(thief[j] - police[i]) <= k){
                ans++;
                i++;
                j++;
            }
            else if(police[i] < thief[j]){
                i++;
            }
            else j++;
        
        }
        return ans;
    }
};