class Solution {
private:
    bool bfs(vector<vector<int>>& graph, vector<int> &color, int i){
        color[i] = 0;
        queue<pair<int,int>> q;
        q.push({i,0});
        while(!q.empty()){
            int node = q.front().first;
            int cols = q.front().second;
            q.pop();
            for(auto it: graph[node]){
                if(color[it]==-1){
                    color[it] = !cols;
                    q.push({it,color[it]});
                }
                else{
                    if(color[it]!=!cols) return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

      int V = graph.size();
      vector<int> color(V,-1);

      // graph may be disconnected so traverse over all vertices and if they are not visisted then
      // run the code but rather than maintaining visisted array lets maintain colot array
      for(int i=0;i<V;i++){
        if(color[i]==-1){
            if(bfs(graph,color,i)==false) return false;
        }
      }
      return true;
    }
};