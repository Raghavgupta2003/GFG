class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        //squaring all the values
        // sort(arr.begin(), arr.end());
        // for(int i=0; i<arr.size(); i++){
        //     arr[i] = arr[i]*arr[i];
        // }
        //brute force
        // for(int i=0; i<arr.size(); i++){
        //     for(int j=i+1; j<arr.size(); j++){
        //         for(int k=j+1; k<arr.size(); k++){
        //             if(arr[i]+arr[j] == arr[k]){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
        
        //------trying to optimize it-----
        //------consider each element as C^2------
        
        // for(int i=arr.size()-1; i>=2; i--){ //>=2 as we also need i-1, 0 th
        //     int k=0;
        //     int l=i-1;
            
        //     while(k<=l){
        //         if(arr[k]+arr[l] == arr[i]){
        //             // cout<<arr[k]<<"+"<<arr[l]<<"="<<arr[i];
        //             return true;
        //         }
        //         else if(arr[k]+arr[l] < arr[i]){
        //             k++;
        //         }
        //         else if(arr[k]+arr[l] > arr[i]){
        //             l--;
        //         }
        //     }
            
        // }
        
        // return false;
        
        //---------Again Optimize it----------
        
        unordered_map<int, int> sq;
        for(int i=0; i<arr.size(); i++){
            sq[arr[i] * arr[i]] = i;
        }
        
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                int sum = (arr[i]*arr[i])+ (arr[j]*arr[j]);
                if(sq.find(sum) != sq.end() && sq[sum]!=i && sq[sum]!=j){
                    return true;
                }
            }
        }
        return false;
    }
};