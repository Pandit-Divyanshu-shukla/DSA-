#define pii pair<int,int>
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue<pii> pq;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        vector<int> ans;
        
        int i=0, j=0;
        int size = a.size();
        int sum=b[j]+a[i];
        while(size-->0){
            pq.push({b[j]+a[i++],j});
        }
        
        while(!pq.empty() && k-->0){
            int sum = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(idx+1<b.size()){
                pq.push({sum-b[idx]+b[++idx],idx});
            }
            ans.push_back(sum);
        }
        return ans;
    }
};