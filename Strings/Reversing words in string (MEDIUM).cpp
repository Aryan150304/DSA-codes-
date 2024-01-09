// leetcode solution - https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string reverseWords(string s) {
        vector<string> str;
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                str.push_back(ans);
                ans ="";   
            }
            else{
                 ans.push_back(s[i]);
            }
           
        }
        if(ans!=" "){
  str.push_back(ans);
        }
        
          string finalans="";
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]!=""){
                 finalans+=str[i];
                // we can onky add chars but we can concatenate these strings
                finalans.push_back(' ');
            }
        }
        finalans.pop_back();
          
        
        return finalans;
        // appraoch is to push all
    }
};


// approach 2 - 

// isme idea ye hai ki string ko piche se traverse krte hai and space encounter hote hi reverse krdete hai selected string ko and
// ans string me puch kr dete isse ik hi loop me saari string reverse hoke puch ho jaati hai 
class Solution {
public:
    string reverseWords(string s) {
        int len=s.size()-1;
        string temp="";
        string ans="";
        for(int i=len;i>=0;i--){
            if(s[i]==' ' && temp!=""){
                reverse(temp.begin(),temp.end());
                ans+=temp+' ';
                temp="";
            }
            else{
                if(s[i]==' ')   continue;
                temp+=s[i];
            }
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        if(ans[ans.size()-1]==' ')
            //ans=ans.erase(ans.size()-1);
            ans.pop_back();
        return ans;
    }
};
