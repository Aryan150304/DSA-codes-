#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    /*
    Intuition is to push the elements into the stack from back until we find any element smaller than them 
    as soon as we find element smaller than them we store that value
    and move the same
    */
    vector<int>ans(arr.size());
    stack<int> stack;
    stack.push(-1);
    for(int i=arr.size()-1;i>=0;i--){
        int element = arr[i];
        while(element<=stack.top()){
            stack.pop();
        }
        ans[i]= stack.top();
        stack.push(element);
    }
    return ans;
}
