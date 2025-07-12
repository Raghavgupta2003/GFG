
class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<int> st;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if(st.size() > 0){
                if(s[i] == ')' && st.top()=='(') st.pop();
                else if(s[i] == '}' && st.top()=='{') st.pop();
                else if(s[i] == ']' && st.top()=='[') st.pop();
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }
        
        return st.size() == 0;
        
    }
};