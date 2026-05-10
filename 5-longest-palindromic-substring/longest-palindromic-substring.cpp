class Solution {
public:
    // bool chkPalindrome(string s, int st, int end){

    //     while(st<end){
    //         if(s[st++]!=s[end--]){
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    void chkExpansion(string s, int l, int r, string &ans){
        

        while(l>=0 && r<s.length() && s[l]==s[r]){
            if((r-l+1) > ans.length()){
                ans = s.substr(l,r-l+1);
            }
            l--;
            r++;
        }
    }
    // void generateSubstrings(string s, string &ans){
    //     for(int i=0; i<s.length(); i++){
    //         char ch = s[i];
    //         string sub ="";
    //         sub+=ch;
    //         if(chkPalindrome(sub) && ans.length()<sub.length()){
    //             ans = sub;
    //         }
    //         for(int j=i+1; j<s.length(); j++){
    //             sub+=s[j];
    //             if(chkPalindrome(sub) && ans.length()<sub.length()){
    //                 ans = sub;
    //             }
    //         }
    //     }
    // }
    string longestPalindrome(string s) {
        string ans = "";

        for(int i=0; i<s.length(); i++){
            // even expansion
            chkExpansion(s,i,i+1,ans);
            // odd expansion
            chkExpansion(s,i,i,ans);
        }
        return ans;
    }
};