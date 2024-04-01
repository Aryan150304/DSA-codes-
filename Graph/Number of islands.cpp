class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 || j == 0) {
                        int delrow = nrow + i;
                        int delcol = ncol + j;
                        if (delrow >= 0 && delrow < n && delcol >= 0 &&
                            delcol < m && grid[delrow][delcol] == '1' &&
                            !vis[delrow][delcol]) {
                            vis[delrow][delcol] = 1;
                            q.push({delrow, delcol});
                        }
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // now i have to traverse every element
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == '1' && !vis[row][col]) {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }
};
