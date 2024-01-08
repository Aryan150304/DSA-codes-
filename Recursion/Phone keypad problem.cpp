// leetcode problem medium - https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:

   void solve(string digits,int n,int index,string output,vector<string>&ans, string mapping[]){
       if(index>=n){
           ans.push_back(output);
           return ;
       }
       int element = (digits[index]-'0');
       string value = mapping[element];

       for(int i=0;i<value.length();i++){
           output.push_back(value[i]);
           solve(digits, n , index+1, output, ans, mapping);
           output.pop_back();
       }
       
   }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output;
        string mapping[10]= {"","", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
        int n = digits.length();
        int index = 0;
        solve(digits, n , index, output, ans, mapping);
        return ans;
    }
};
