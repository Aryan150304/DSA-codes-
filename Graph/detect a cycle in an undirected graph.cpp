// the main catch in this question that is graph can not be always connected so we have to traverse all the nodes to insure proper BFS is done
class Solution {
    private:
    bool bfs(int vis[], int V, int i, vector<int> adj[]){
                queue<pair<int,int>> q;
        vis[i] =1;
        q.push({i,-1});
        while(!q.empty()){
            int element = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it: adj[element]){
                if(!vis[it]){
                       vis[it]= 1;
                    q.push({it,element});
                }
                else{
                    if(it!=parent){
                        return true;
                    }
                }
            }
        }
        return false; 
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        // graph wont be connected

        // we have to also take the count of parent element
        int vis[V] ={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
               bool value =  bfs(vis,V,i,adj);
               if(value){
                   return true;
               }
            }
        }
        return false;
    }
};
