// daily problem - https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15

// approach 
class Solution {
public:

    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        int winMax = 0;
        int defMax = 0;
        for (int i = 0; i < matches.size(); i++) {
            for (int j = 0; j < 2; j++) {
                if (j == 0) {
                    if (matches[i][j] > winMax) {
                        winMax = matches[i][j];
                    }
                } else {
                    if (matches[i][j] > defMax) {
                        defMax = matches[i][j];
                    }
                }
            }
        }
        int maxi = max(winMax,defMax);
        cout<<maxi;
        
        vector<int> win(maxi+1, 0);
        vector<int> defeat(maxi+1, 0);
        for (int i = 0; i < matches.size(); i++) {
            for (int j = 0; j < 2; j++) {
                if (j == 0) {
                    cout<<matches[i][j]<<endl;
                    win[matches[i][j]]++;
                } else {
           
                    defeat[matches[i][j]]++;
                }
            }
        }
      
        // defeat array consist of how many times that index has been defeated 
        // winn array consis of how many times that index have won
        vector<int> alwayswin;
        vector<int> onedefeat;
        for (int i = 0; i < defeat.size(); i++) {
            if (defeat[i] == 0) {
                if(i<win.size()&&win[i]>0){
                     alwayswin.push_back(i);
                }
               
            }
            else if(defeat[i]==1){
                onedefeat.push_back(i);
            }
        }

        ans.push_back(alwayswin);
        ans.push_back(onedefeat);
        return ans;
    }
};
