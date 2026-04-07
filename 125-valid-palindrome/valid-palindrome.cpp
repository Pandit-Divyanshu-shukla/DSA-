class Solution {
public:
    bool isPalindrome(string s) {
        

        string str = "";

        for(char ch: s){
            ch = tolower(ch);
            if(isalnum(ch)){
                str+=ch;
            }
        }

        cout<<str<<endl;

        int st = 0;
        int end = str.length()-1;

        while(st<=end){
            cout<<str[st]<<" "<<str[end]<<endl;
            if(str[st]!=str[end]){
                return false;
            }
            st++;
            end--;
        }

        // cout<<str<<endl;
        return true;
    }
};