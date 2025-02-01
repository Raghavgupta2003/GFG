//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int binarySearchfirst(vector<int> &arr, int target){
        int cnt = 0;
        int low = 0;
        int high = arr.size()-1;

        while(low<=high){
            int mid = low + ((high-low)/2);

            if(arr[mid]==target){
                if(mid!=0 && arr[mid-1] == target){
                    cnt++;
                    high = mid-1;
                }else{
                    return mid;
                }
            }
            else if(arr[mid] < target) low = mid+1;
            else if(arr[mid] > target) high = mid-1;
        }

        return -1;
    }

     int binarySearchlast(vector<int> &arr, int target){
        int cnt = 0;
        int low = 0;
        int high = arr.size()-1;
        

        while(low<=high){
            int mid = low + ((high-low)/2);

            if(arr[mid]==target){
                if(mid!=arr.size()-1 && arr[mid+1] == target){
                    low = mid+1;
                    cnt++;
                }else{
                    return mid;
                }
            }
            else if(arr[mid] < target) low = mid+1;
            else if(arr[mid] > target) high = mid-1;
        }

        return -1;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first = binarySearchfirst(arr, target); 
        int last = binarySearchlast(arr, target);
        if(first == -1 && last == -1) return 0;
        return last-first + 1;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends