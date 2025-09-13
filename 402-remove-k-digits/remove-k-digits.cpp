class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        string ans = "";
        for(char ch: num){
            while(!st.empty() && ch<st.back() && k){
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }

        while(k && !st.empty()){ st.pop_back(); k--; }

        int idx = 0 ;
        while(idx<st.length() && st[idx]=='0'){
            idx++;
        }

        ans = st.substr(idx);

        if(ans.empty()){
            return "0";
        }
        return ans;
    }
};