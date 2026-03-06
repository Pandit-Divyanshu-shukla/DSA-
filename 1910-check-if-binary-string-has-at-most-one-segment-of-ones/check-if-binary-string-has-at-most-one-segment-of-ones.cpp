class Solution {
public:
    bool checkOnesSegment(string s) {
        int count=0;
        for(int i=1; i<s.size(); i++){
            if(s[i]-'0'==0) count++;
            else if(count && s[i]-'0'==1) return false;
        }
        return true;
    }
};