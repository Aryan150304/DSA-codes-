#include <bits/stdc++.h> 
void solve(stack<int> &stack, int ans){
    if(stack.empty()||ans>stack.top()){
        stack.push(ans);
        return ; 
    }
        int num = stack.top();
        stack.pop();
        solve(stack,ans);
        stack.push(num);
        return ;
}
void sortStack(stack<int> &stack)
{
    if(stack.empty()){
        return ;
    }
    int ans = stack.top();
    stack.pop();
    sortStack(stack);
    solve(stack,ans);
}
