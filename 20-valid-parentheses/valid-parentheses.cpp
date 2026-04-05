#define small (s[i]==')' && !st.empty() && st.top()=='(')
#define curly (s[i]=='}' && !st.empty() && st.top()=='{')
#define big (s[i]==']' && !st.empty() && st.top()=='[')
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(small || curly || big){
                    st.pop();
                }else{
                    return false;
                }
            }
        }

        return st.empty();
    }
};