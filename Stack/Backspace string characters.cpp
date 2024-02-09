class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stacks;
        stack<char> str;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'&&stacks.size()>0){
                stacks.pop();
            }
            else if(s[i]!='#'){
                stacks.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'&&str.size()>0){
                str.pop();
            }
            else if(t[i]!='#'){
                str.push(t[i]);
            }
        }
        if(stacks.size()!=str.size()){
            return false;
        }

        while((!stacks.empty())&&(!str.empty())){
            int ans = stacks.top();
            int preans = str.top();
            if(ans!=preans){
                return false;
            }
            stacks.pop();
            str.pop();
        }
        return true;
    }
};
