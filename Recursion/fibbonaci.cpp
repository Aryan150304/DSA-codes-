
#include <iostream>

using namespace std;
int fib(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    int sum = fib(n-1)+fib(n-2);
    return sum;
}

int main()
{
    int num ;
    cout<<"Enter the fibbonaci term"<<endl;
    cin>>num;
    cout<<fib(num)<<endl;
}
