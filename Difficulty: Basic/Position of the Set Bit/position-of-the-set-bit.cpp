class Solution {
  public:
    #include <stdio.h>

    int findPosition(int n) {
        if(n&(n-1)) return -1;
        
        for(int i=0; i<32; i++){
            if(n == 1<<i) return i+1;
        }
    }
};