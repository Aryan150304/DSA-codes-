// leetcode daily problem solution - https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> aryan;
        for(string str: bank){
        int numberOfOnes = count(str.begin(), str.end(), '1');
        if(numberOfOnes>0){
            aryan.push_back(numberOfOnes);
        }
        }
        // O(n2)
        if(aryan.size()==0||aryan.size()==1){
            return 0;
        }
        int n = aryan.size();
        int laserSum = 0;
        for(int i =0;i<n-1;i++){
            laserSum += aryan[i]*aryan[i+1];
        }
        return laserSum;
        
    }
};
