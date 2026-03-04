#define pii pair<int,int>
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int s = graph.size();

        vector<bool> visited(graph.size(),false);
        vector<bool> color(graph.size());

        bool ans = false;

        for(int i=0; i<s; i++){
        
            bool c = 0;
            int src = i;
            if(!visited[i]){
                queue<int> q;
                q.push(src);

                visited[src] = true;
                color[src] = c;

                while(!q.empty()){
                    int node = q.front(); q.pop();
                    bool col = color[node];

                    for(int v: graph[node]){
                        if(!visited[v]){
                            q.push(v);
                            visited[v] = true;
                            color[v] = !col;
                        } else if(color[node] == color[v]) return false;
                    } 
                }
                
            }
        }
        return true;
    }

        
};