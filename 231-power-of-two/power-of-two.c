bool isPowerOfTwo(int n) {
    long no = n;
    if(no==0) return false;
    return (no & no-1) == 0 ? true : false;
}