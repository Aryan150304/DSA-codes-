class Solution {
    private:
    bool dfs(vector<vector<int>>& adj, vector<int> &vis,vector<int>&path, int i){
        // as soon as we lead to graph we return false and all 
        // the nodes in path remain as it is and we move ahead

        vis[i] =1;
        path[i] =1;

        for(auto it: adj[i]){
            // u have to check if adjacent have been visiyed
            if(!vis[it]){
                if(!dfs(adj,vis,path,it)) return false;
            }
            else if(path[it]== true){
                return false;
            }
        }
        vis[i]= 2;
        path[i]=0;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // so we have an adjacency list 
        int n = graph.size();
        vector<int> safeNodes;
       
        vector<int> vis(n,0);
         vector<int> path(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,vis,path,i);
            }
        }

        for(int i=0;i<n;i++){
            if(vis[i]==2){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};