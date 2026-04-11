class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int ans=0;

        for(char ch: s){
            if(st.find(ch)!=st.end()){
                ans+=2;
                st.erase(ch);
            }
            else{
                st.insert(ch);
            }
        }

        if(!st.empty())return ans+1;
        else return ans;
    }
};