class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[255] = {0};
        int n = s.length();

        if(n<=1) return n;

        int ans=INT_MIN;

        string sub;
        for(int i=0; i<n; i++){
            sub = "";
            for(int j=i; j<n; j++){
                if(arr[(int)s[j]]){
                    break;
                }else{
                    arr[(int)s[j]]++;
                    sub+=s[j];
                    ans = max(ans,j-i+1);
                }
            }
            memset(arr, 0, sizeof(arr));
        }

        return ans;

    }
};