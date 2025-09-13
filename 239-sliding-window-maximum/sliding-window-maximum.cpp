class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> max_wndw;
        int n = nums.size();

        for(int i=0; i<k; i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        max_wndw.push_back(nums[dq.front()]);

        for(int i=k; i<n; i++){

            int s_idx = i-k+1;
            while(!dq.empty() && dq.front()<s_idx){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            max_wndw.push_back(nums[dq.front()]);
        }

        // max_wndw.push_back(nums[dq.front()]);
        return max_wndw;
    }
};