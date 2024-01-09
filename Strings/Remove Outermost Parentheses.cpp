// leetcode problem - https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string s) {

int level =0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(level==0){
                    s[i]=' ';
                }
                level++;
            }
            else{
                if(level==1){
                    s[i]=' ';
                }
                level--; 
            }
        }
        string finalans= "";
         for(int i=0;i<n;i++){
             if(s[i]!=' '){
                 finalans+=s[i];
             }
        }
        return finalans;
        
    }
};
