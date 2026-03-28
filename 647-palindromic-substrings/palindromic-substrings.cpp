class Solution {
public:
    bool solve(int st, int end, string &s){
        if(st>=end){
            return true;
        }

        if(s[st]==s[end]){
            return solve(st+1,end-1,s);
        }else{
            return false;
        }

        return true;

    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(solve(i,j,s)){
                    count++;
                }
            }
        }
        return count;
    }
};