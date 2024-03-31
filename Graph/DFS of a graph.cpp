class Solution {
    private: 
    void dfscall(int node, vector<int> adj[], int vis[], vector<int> &dfs){
        vis[node] = 1;
        dfs.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                dfscall(it, adj, vis, dfs);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // we have to go the max depth 
        // so we have to make a function that goes to max depth
        int vis[V] ={0};
        vector<int> dfs;
        int node = 0;
        dfscall(node,adj,vis,dfs);
        return dfs;
    }
};
