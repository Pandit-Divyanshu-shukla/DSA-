#define pii pair<int,int>
#define Node pair<int,pii>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Node,vector<Node>,greater<Node>> pq;
        vector<vector<int>> res;
        for(auto pnt: points){
            int x = pnt[0];
            int y = pnt[1];

            int dist_sq = x*x + y*y;

            pq.push({dist_sq,{x,y}});
        }

        while(k){
            vector<int> tp_Node;
            int p1 = pq.top().second.first;
            tp_Node.push_back(p1);
            int p2 = pq.top().second.second;
            tp_Node.push_back(p2);

            pq.pop();

            res.push_back(tp_Node);
            k--;
        }

        return res;
    }
};