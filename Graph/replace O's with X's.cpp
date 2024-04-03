class Solution {
private:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int row,
             int col) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0||j==0){
                    int newrow = row+i;
                    int newcol = col+j;
                    if(newrow>=0&&newrow<n&&newcol>=0&&newcol<m&&!vis[newrow][newcol]&&board[newrow][newcol]=='O'){
                         dfs(board, vis, newrow, newcol);
                    }
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        // so first traverse 4 boundaries and find 0 and appl;y dfs over it
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0;i < m; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                dfs(board, vis, 0, i);
            }
             if (board[n - 1][i] == 'O' && !vis[n - 1][i]) {
                dfs(board, vis, n - 1, i);
            }
        }

        for (int i = 0;i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(board, vis, i, 0);
            }
             if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(board, vis, i, m - 1);
            }
        }

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(vis[i][j]==1&&board[i][j]=='O'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};
