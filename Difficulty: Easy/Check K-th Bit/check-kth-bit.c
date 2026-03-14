#include <stdbool.h>
int checkKthBit(int n, int k) {
    // code here
    if((1<<k)&n) return true;
    return false;
}