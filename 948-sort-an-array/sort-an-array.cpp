class Solution {
public:
    void maxHeapify(vector<int>& nums, int i, int n){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int maxI = i;

        if(l<n && nums[l]>nums[maxI]){
            maxI = l;
        }

        if(r<n && nums[r]>nums[maxI]){
            maxI = r;
        }

        if(maxI != i){
            swap(nums[maxI],nums[i]);
            maxHeapify(nums,maxI,n);
        }
    }

    void heapSort(vector<int>& nums){
        int n = nums.size();
        // Creating HEap
        for(int i=n/2-1; i>=0; i--){
            maxHeapify(nums,i,n);
        }

        //Fixing Positions
        for(int i=n-1; i>=0; i--){
            swap(nums[0],nums[i]);
            maxHeapify(nums,0,i);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};