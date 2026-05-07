// User function Template for C++
class Solution {
  public:
    string isAdjacentSetBits(long long int n) {
        // code here
        if(n&(n>>1))return "Yes";
        return "No";
    }
};