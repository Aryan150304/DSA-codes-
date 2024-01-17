// leetcode link - https://leetcode.com/problems/unique-number-of-occurrences/submissions/1148495951/?envType=daily-question&envId=2024-01-17

// approach 1 - store the frequency in an array or a hashmap . Iterate the array/hashmap to find if the occurences are same or not 
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        // 1 1 1 2 2 3 
        vector<int> count;
        int checker  = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=arr[i-1]){
                count.push_back(checker);
                checker=0;
            }
            else
            {
                checker++;
            }
            
        }
        count.push_back(checker);
        sort(count.begin(),count.end());
        for(int i=0;i<count.size()-1;i++){
            if(count[i]==count[i+1]){
                return false;
            }
        }
        return true;
}
};

/* 
approach 2 - Rather than sorting the array and increasing time complexity, store the frequency in a hashmap and then store the elements 
of that hashmap in a set. Set stores only unique elements so if the occurences will be same it will not store so if the sixze of set and hashmap is uqual
thn return true
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    
        unordered_map<int,int> freq;

        for(auto val: arr)
        {
            freq[val]++;
        }

        unordered_set<int> st;

        for(auto val: freq)
        {
            if(st.count(val.second)) return false;
            st.insert(val.second);
        }

        return true;
    }

// 2 hashmap approach  
//set stores only unique elements 
// store the frequency of all elements in a hashmap now store the elements of hashmap in set . if the size of set is equal to hashmap size then its true else its false

};
