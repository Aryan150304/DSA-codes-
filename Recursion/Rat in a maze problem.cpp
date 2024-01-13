// gfg link - 


class Solution{
    public:
    bool isSafe(vector<vector<int>>&m , int n, int srcx, int srcy,vector<vector<int>> &visited){
        if((srcx>=0&&srcx<n)&&(srcy>=0&&srcy<n)&&(visited[srcx][srcy]!=1)&&(m[srcx][srcy]==1)){
            return true;
        }
       return false;
    }
    
    void solve(vector<vector<int>>&m , int n, int srcx, int srcy, vector<vector<int>> visited, string output, vector<string>&ans ){
        // base conditon 
        if(srcx==n-1&&srcy==n-1){
            ans.push_back(output);
            return ;
        }
        
        if(n==0){
            return ;
        }
        
        visited[srcx][srcy] = 1;
        // main condition 
        
        // if down cinditon - x+1 , y 
        if(isSafe(m,n,srcx+1,srcy,visited)==true){
            output.push_back('D');
            solve (m,n,srcx+1,srcy,visited, output, ans);
            output.pop_back();
        }
        // down condition
        
        // right conditon - x, y+1
         if(isSafe(m,n,srcx,srcy+1,visited)==true){
            output.push_back('R');
            solve (m,n,srcx,srcy+1,visited, output, ans);
            output.pop_back();
        }
        // left condition  --> x , y-1 
        
         if(isSafe(m,n,srcx,srcy-1,visited)==true){
            output.push_back('L');
            solve (m,n,srcx,srcy-1,visited, output,ans);
            output.pop_back();
        }
        // up condition --> x-1, y 
        
         if(isSafe(m,n,srcx-1,srcy,visited)==true){
            output.push_back('U');
            solve (m,n,srcx-1,srcy,visited, output, ans);
            output.pop_back();
        }
        // in case of backtrack remove 1 
         visited[srcx][srcy] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0){
            ans.push_back("-1");
            return ans;
        }
        // you have a 2d array were src is given 
        int srcx = 0;
        int srcy = 0;
        string output;
       
        // create a 2d array the shows the visited nodes
        vector<vector<int>> visited(n,vector<int>(n,0));
        // Your code goes here
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        solve (m,n,srcx,srcy,visited,output,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
