class Solution {
  public:
    bool isPowerofTwo(int n) {
        // code here
        for(int i=0; i<32; i++){
            if(1<<i == n)return true;
        }
        
        return false;
    }
};