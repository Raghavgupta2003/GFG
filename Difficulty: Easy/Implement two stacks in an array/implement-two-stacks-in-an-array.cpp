//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks {
  public:
    int *arr;//given in constraints size=100
    int size;
    int top1;
    int top2;
    twoStacks() {
        
        size=100;
        arr=new int[size];
        top1=0;
        top2=size-1;
        
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if(top1>top2) return; //overflow condition
        arr[top1]=x;
        top1++;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(top1>top2) return; //overflow condition
        arr[top2]=x;
        top2--;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(top1==0) return -1;
        top1--;
        return arr[top1];
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2==size-1) return -1;
        top2++;
        return arr[top2];
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends