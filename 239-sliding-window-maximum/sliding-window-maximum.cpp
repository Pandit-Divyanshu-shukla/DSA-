#define pii pair<int,int>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pii> pq;
        vector<int> max_wndw;
        int n = nums.size();

        for(int i=0; i<k; i++){
            pq.push({nums[i],i});
        }

        max_wndw.push_back(pq.top().first);

        for(int i=k; i<n; i++){

            int s_idx = i-k+1;
            while(!pq.empty() && pq.top().second<s_idx){
                pq.pop();
            }

            
            pq.push({nums[i],i});
            max_wndw.push_back(pq.top().first);
        }

        return max_wndw;
    }
};