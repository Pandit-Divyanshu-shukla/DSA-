bool isPowerOfTwo(int n) {
    long n0 = n;
    if(n0==0) return false;
    long long bitMask = n0-1;
    if(n0&(bitMask))return false;
    return true;
}