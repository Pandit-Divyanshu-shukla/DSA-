class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1;
        int suf = 1;
        int maxProduct = INT_MIN;
        
        for(int i=0; i<n; i++){
            pre*=nums[i];
            maxProduct = max(pre,maxProduct);
            if(pre==0){
                pre=1;
            }
        }
        for(int i=n-1; i>=0; i--){
            suf*=nums[i];
            maxProduct = max(suf,maxProduct);
            if(suf==0){
                suf=1;
            }
        }

        return maxProduct;
    }
};