class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        vector<pair<int, int>> v;
        
        for(int i=0; i<arr.size(); i++){
            v.push_back({arr[i], 0});
        }
        
        for(int i=0; i<dep.size(); i++){
            v.push_back({dep[i], 1});
        }
        
        sort(v.begin(), v.end());
        
        int cnt = 0;
        int maxplatform = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i].second == 0){
                cnt++;
                maxplatform = max(maxplatform, cnt);
            }
            if(v[i].second == 1) cnt--;
        }
        return maxplatform;
    }
};
