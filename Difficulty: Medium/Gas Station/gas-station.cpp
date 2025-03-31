//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*You are required to complete this method*/
// class Solution {
//   public:
//     int startStation(vector<int> &gas, vector<int> &cost) {
//         // Your code here
//         int n = cost.size();
//         for(int i=0; i<n; i++){
//             int gass = 0;
//             for(int j=i; j<2*n; j++){
//                 gass += gas[j%n];
                
//                 if(gass >= cost[j%n]) gass -= cost[j%n];
//                 else break; // can't move
//                 if(j!=i && j%n == i) return i;
//             }
//         }
        
//         return -1;
//     }
// };

//---------------------------------------------------------------

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        
        //basecase -> when no required station exist
        int total_gas = 0;
        int total_cost = 0;
        for(int i=0; i<gas.size(); i++){
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if(total_cost > total_gas) return -1;
        
        //if required station exist
        int start  = 0;
        int cur_gas = 0;
        for(int i=0; i<gas.size(); i++){
            cur_gas += gas[i] - cost[i];
            
            if(cur_gas < 0){ // it means we cannot move further, 
            //so we start our journey from next statation i.e. i+1
                start = i+1;
                cur_gas = 0;
            }
        }
        
        return start;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends