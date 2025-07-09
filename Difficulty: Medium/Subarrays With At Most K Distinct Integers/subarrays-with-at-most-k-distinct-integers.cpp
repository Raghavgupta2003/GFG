class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int i=0; 
        int j=0;
        
        unordered_map<int, int> m;
        int ans = 0;
        int cnt = 0;
        while(i<arr.size()){
            m[arr[i]]++;
            if(m[arr[i]] == 1){
                cnt++;
            }
            
            while(cnt > k && j<i){
                m[arr[j]]--;
                if(m[arr[j]]==0){
                    cnt--;
                     m.erase(arr[j]);
                }
                j++;
            }
            
            ans += i-j+1;
            
            i++;
        }
        return ans;
    }
};