// User function Template for C++

class Solution {
  public:
    void pushAtLast(int x, stack<int> &st){
        stack<int> temp;
        while(st.size()>0){
            temp.push(st.top());
            st.pop();
        }
        //after emplting stack, push it in stack
        st.push(x);
        //push remaining ele in stack
        while(temp.size()>0){
            st.push(temp.top());
            temp.pop();
        }
        
    }
    void rev(int i, int n, stack<int> &St){
        if(i >= n) return;
        int x = St.top();
        St.pop();
        rev(i+1, n, St);
        pushAtLast(x, St);
    }
    void Reverse(stack<int> &St) {
        int n = St.size();
        rev(0, n, St);
    }
};