class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        queue<int>q;
        int visited[V]= {0};
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            // har ik element ko queue me daalpo aur pop kro aur uske adjacent ko bhi daale
            for(auto it: adj[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};
