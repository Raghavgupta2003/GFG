class Solution {
  public:
    void maximum(int i, vector<int> &arr, int &maxi){
        if(i>=arr.size()) return;
        
        maxi = max(maxi, arr[i]);
        maximum(i+1, arr, maxi);
    }
    int largest(vector<int> &arr) {
        // code here
        int maxi = INT_MIN;
        maximum(0, arr, maxi);
        
        return maxi;
    }
};
