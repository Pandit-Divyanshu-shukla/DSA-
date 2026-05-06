#include <stdbool.h>
int checkKthBit(int n, int k) {
    // code here
    int bitMask  = 1<<k;
    if(n&bitMask) return 1;
    return 0;
    
}