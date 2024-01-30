// coding ninjas link - https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio&leftPanelTabValue=PROBLEM

void solve(stack<int> &stack,int ans){
    if(stack.empty()){
        stack.push(ans);
        return ;
    }
    int num = stack.top();
    stack.pop();
    solve(stack,ans);
    stack.push(num);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return ;
    }
    int ans = stack.top();
    stack.pop();
    reverseStack(stack); 
    solve(stack,ans);
}
