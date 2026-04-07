class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.length()-1;

        while(st<=end){
            if(!isalnum(s[st])){
                st++;
                continue;
            }
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            
            if(isalnum(s[st]) && isalnum(s[end])){
                cout<<s[st]<<" "<<s[end]<<endl;
                if(tolower(s[st])!=tolower(s[end])){
                    return false;
                }
            }
            st++;
            end--;
            
        }

        // cout<<str<<endl;
        return true;
    }
};