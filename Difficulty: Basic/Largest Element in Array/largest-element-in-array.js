
class Solution {
    /**
    * @param number[] arr

    * @returns number
    */
    largest(arr) {
        // code here
        let maximum = 0;
        for(let i=0; i<arr.length; i++){
            if(arr[i]>maximum) maximum = arr[i];
        }
        
        return maximum;
    }
}
