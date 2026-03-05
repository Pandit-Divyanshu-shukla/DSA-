class Solution {
public:
    int minOperations(string s) {

        int p1 = 0; 
        int p2=0;

        for(int i=0; i<s.size(); i++){
            //010101...
            if((s[i]-'0')!=(i%2)){
                p1++;
            }
            //10101010...
            if((s[i]-'0')!=((i+1)%2)){
                p2++;
            }
        }

        return min(p1,p2);
    }
};