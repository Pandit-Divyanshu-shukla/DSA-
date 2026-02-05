#define pii pair<int,int>
#define Node pair<int,pii>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;

        priority_queue<Node,vector<Node>,greater<Node>> pq;
        for(auto& p : points){
            int x = p[0];
            int y = p[1];

            int dist_sq = x*x + y*y;
            pq.push({dist_sq,{x,y}});
        }

        while(k){
            vector<int> point;
            int x = pq.top().second.first;
            point.push_back(x);
            int y = pq.top().second.second;
            point.push_back(y);
            pq.pop();
            
            res.push_back(point);
            k--;
        }
        return res;
    }
};