class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        /*
        approach 1 array that stores sum of ones in allrows
        one arraw that stores sum of zeros in rows and same for column
        */
        vector<int> onesRow;
        vector<int> onesCol;
        vector<int> zerosRow;
        vector<int> zerosCol;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            int zeroSum = 0;
            int oneSum =0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) zeroSum++;
                else oneSum++;
            }
            onesRow.push_back(oneSum);
            zerosRow.push_back(zeroSum);
        }
        for(int j=0;j<n;j++){
            int zeroSum = 0;
            int oneSum =0;  
            for(int i=0;i<m;i++){
                if(grid[i][j]==0) zeroSum++;
                else oneSum++;
            }
           onesCol.push_back(oneSum);
           zerosCol.push_back(zeroSum);
        }

        vector<vector<int>> diff(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j] = onesRow[i] + onesCol[j] -(zerosRow[i] + zerosCol[j]);
            }
        }
        return diff;

    }
};
