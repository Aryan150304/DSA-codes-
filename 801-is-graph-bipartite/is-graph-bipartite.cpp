class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int i, int col){
        color[i] = !col;
        for(auto it: graph[i]){
            if(color[it]==-1){
                if(dfs(graph,color,it,!col)==false) return false;
            }
            else{
                if(color[it]!=col) return false;
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
            if(dfs(graph,color,i,0)==false) return false;
        }
      }
      return true;
    }
};