class Solution {
public:
    string reverseWords(string s) {
        int st = 0;
        int end = s.length()-1;

        string ans = "";

        while(st<end){
            swap(s[st++],s[end--]);
        }

        string word = "";

        for(char ch: s){
            if(ch!=' '){
                word = ch + word;
            }else{
                if(!word.empty()){
                    if(!ans.empty()) ans+=" ";
                    ans+=word;
                    word="";
                }
            }
        }

        //last word
        if(!word.empty()){
            if(!ans.empty()) ans += " ";
            ans+=word;
        }

        return ans;

    }
};