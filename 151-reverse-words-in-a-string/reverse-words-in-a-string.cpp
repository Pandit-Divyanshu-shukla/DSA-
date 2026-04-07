class Solution {
public:
    string reverseWords(string s) {
        string ans= "";
        int st = 0, end = s.length()-1;
        while(st<=end){
            swap(s[st++],s[end--]);
        }

        cout<<s<<endl;

        string word = "";
        for(char ch: s){
            if(ch!=' '){
                word = ch + word;
            }else{
                if(word!=""){
                    if(!ans.empty()) ans+=" ";
                    ans += word;
                }
                word="";
            }
        }

        // last word
        if(!word.empty()){
            if(!ans.empty()) ans+=" ";
            ans+= word;
        }
        
        return ans;
    }
};