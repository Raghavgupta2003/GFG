// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        //we find index of minimum element to know the number of rotations done
        // Code Here
        int low = 0;
        int high = nums.size()-1;
        
        int ans = INT_MAX;
        int ansIdx = -1;
        while(low<=high){
            int mid = low + ((high - low)/2);


            if(nums[low] <= nums[mid]){
                //left part sorted half
                if(nums[low] <= ans){
                    ans = nums[low];
                    ansIdx = low;
                }
                low = mid+1; //we exit from sorted half
            }


            if(nums[mid] < nums[nums.size()-1]){
                //right part is sorted half
                if(nums[mid] < ans){
                    ans = nums[mid];
                    ansIdx = mid;
                }
                high = mid-1; //we exit from right sorted
            }
        }

        return ansIdx;
    }
};
