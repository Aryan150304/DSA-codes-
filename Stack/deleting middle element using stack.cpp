#include <bits/stdc++.h> 
void solve(stack<int>&stack, int count, int size){
   if(count==size/2){
      stack.pop();
      return ;
   }
   int ans = stack.top();
   stack.pop();
   solve(stack, count+1, size);
   stack.push(ans);
}

void deleteMiddle(stack<int>&inputStack, int N){
   int count =0;
   solve(inputStack,count,N);
}
