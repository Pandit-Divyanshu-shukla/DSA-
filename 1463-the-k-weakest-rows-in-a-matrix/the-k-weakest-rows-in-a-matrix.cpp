#define pii pair<int,int>
class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> &p1, pair<int,int> &p2) {
        if(p1.first==p2.first){
                return p1.second>p2.second; // true->less priority to left
            }
            return p1.first>p2.first;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pii,vector<pii>,cmp> pq;
        vector<int> res;
        for(int i=0; i<mat.size(); i++){
            int sum=0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j])
                    sum++;
            }
            pq.push({sum,i});
        }
        while(k){
            int idx = pq.top().second; pq.pop();
            res.push_back(idx);
            k--;
        }
        return res;
    }
};