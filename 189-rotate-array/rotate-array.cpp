class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> arr = nums;
        for(int j=0; j<arr.size(); j++){
            nums[(j+k)%nums.size()] = arr[j];
        }
    }
};