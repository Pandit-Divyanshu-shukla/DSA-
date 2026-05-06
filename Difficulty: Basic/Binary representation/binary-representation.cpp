class Solution {
  public:
    string getBinaryRep(int n) {
        // Write Your Code here
        string ans = "";
        for(int i=31; i>=0; i--){
            int curr = 1<<i;
            if(n-curr>=0){
                ans = ans + "1";
                n-=curr;
            }else{
                ans = ans + "0";
            }
        }
        
        // cout<<ans<<endl;
        
        return ans;
    }
};