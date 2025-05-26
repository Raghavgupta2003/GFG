class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        vector<int> v;
        for(int i=0; i<arr.size(); i++){
            int x = (A*arr[i]*arr[i]) + (B*arr[i]) + C;
            v.push_back(x);
        }
        
        sort(v.begin(), v.end());
        return v;
    }
};