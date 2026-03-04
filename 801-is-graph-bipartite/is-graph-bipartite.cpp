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
            pii src = {i,c};
            if(!visited[i]){
                queue<pii> q;
                q.push(src);

                visited[src.first] = true;
                color[src.first] = c;

                while(!q.empty()){
                    pii node = q.front(); q.pop();
                    bool col = node.second;

                    for(int v: graph[node.first]){
                        if(!visited[v]){
                            q.push({v,!col});
                            visited[v] = true;
                            color[v] = !col;
                        } else if(col == color[v]) return false;
                    } 
                }
                
            }
        }
        return true;
    }

        
};