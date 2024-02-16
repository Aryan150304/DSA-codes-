class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // map me map kro and then ik pair bnao
        // aur uss pair ko sort kro
        // then aage se remove krna chalu kr
        sort(arr.begin(), arr.end());
        int counter = 1;
        vector<int> pairs;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                counter++;
            } else {
                pairs.push_back(counter);
                counter = 1;
            }
        }
         if(counter>0){
           pairs.push_back(counter);
        }
        sort(pairs.begin(), pairs.end());
        for (auto& it : pairs) {
            if (it <= k) {
                int ans = k - it;
                k = ans;
                it = 0;
            } else {
                int ans = it - k;
                it = ans;
                k = 0;
            }
        }
        int count = 0;
        for (auto it : pairs) {
            if (it > 0) {
                count++;
            }
        }
        return count;
    }
};
