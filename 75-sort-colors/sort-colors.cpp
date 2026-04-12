class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0;
        int c1=0;
        int c2=0;
        for(int i: nums){
            if(i==0) c0++;
            else if(i==1) c1++;
            else c2++;
        }
        cout<<c0<<" "<<c1<<" "<<c2<<endl;

        for(int i=0; i<nums.size(); i++){
            while(c0>0){
                nums[i++]=0;
                c0--;
            }
            while(c1>0){
                nums[i++]=1;
                c1--;
            }
            while(c2>0){
                nums[i++]=2;
                c2--;
            }
        }

    }
};