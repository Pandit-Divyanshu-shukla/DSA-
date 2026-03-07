#define INF 1e8
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,INF);
        
        dist[src] = 0;
        // {dist[v],v}
        
        for(int i=0; i<V-1; i++){
            //edge relaxations
            for(auto &e: edges){
                if((dist[e[0]]!= INF) && dist[e[1]] > dist[e[0]] + e[2] ){
                    dist[e[1]] = dist[e[0]] + e[2];
                }
            }
        }
        
        for(auto &e: edges){
                if((dist[e[0]]!= INF) && dist[e[1]] > dist[e[0]] + e[2] ){
                    return {-1};
                }
            }
        
        
        return dist;
        
    }
};
