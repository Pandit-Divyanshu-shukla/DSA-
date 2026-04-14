class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0, end=nums.size()-1;

        if(nums.size()==1){
            if(target==nums[0]) return 0;
            else return -1;
        }

        while(st<=end){
            int mid = st + (end-st)/2;

            if(target==nums[mid]){
                return mid;
            }

            // check if the right part of mid is sorted or not
            if(nums[mid]<=nums[end]){
                // means sorted can search in L2 part
                
                // Now chks whether target comes in the range of L2 or not
                if(nums[mid]<= target && target<=nums[end]){
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }
            else{
                // means right is not sorted search in L1 part
                if(nums[st]<= target && target<=nums[mid]){
                    end = mid-1;
                    
                }else{
                    st = mid+1;
                }
            }
        }
        return -1;
    }
};