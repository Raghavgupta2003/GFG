class Solution {
  public:
    void reverse(int i, int j, vector<int>& arr){
        if(i>j) return;
        swap(arr[i], arr[j]);
        reverse(i+1, j-1, arr);
    }
    void reverseArray(vector<int> &arr) {
        // code here
        reverse(0, arr.size()-1, arr);
    }
};