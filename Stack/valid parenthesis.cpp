// main approach is that the when we need to pop stack should have some element if it doesnot have then return false in that case
// after all transactions stack needs to be empty if it is then return true else return false
// moreover when popping check if the top and ch matches or not
bool matches(char ch, char top){
    if((ch=='('&&top==')')||(ch=='['&&top==']')||(ch=='{'&&top=='}')){
        return true;
    }
    return false;
}
bool isValidParenthesis(string s)
{
    
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='('||ch=='['||ch=='{'){
            st.push(ch);
        }
        else{
            if(st.size()>0&&matches(st.top(),ch)==true){
                st.pop();
            }
            else if(st.size()==0){
                return false;
            }
        }
    }
    if(st.size()==0){
        return true;
    }
    else{
        return false;
    }
}
