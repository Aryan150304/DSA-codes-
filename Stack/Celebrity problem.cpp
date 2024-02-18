
class Solution 
{
    public:
    bool knows(vector<vector<int>>&M, int n, int a , int b){
        if(M[a][b]==1){
            return true;
        }
        return false;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> stack;
        int i = 0;
        for(i;i<n;i++){
            stack.push(i);
        }
        int a;
        int b;
        while(stack.size()>1){
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            if(knows(M,n,a,b)){
                stack.push(b);
            }
            else if(knows(M,n,b,a)){
                stack.push(a);
            }
        }
        int ans = stack.top();
        // row visit
        for(int i = 0;i<M[0].size();i++){
            if(M[ans][i]!=0){
                return -1;
            }
        }
        // row visit
        for(int i = 0;i<M.size();i++){
            if(i==ans){
                if(M[i][ans]!=0){
                    return -1;
                }
            }
            else if(M[i][ans]!=1){
                return -1;
            }
        }
        
        return ans;
        
    }
};
