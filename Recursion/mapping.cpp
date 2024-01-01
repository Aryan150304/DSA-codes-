// problem statement is that if the user gives the number 412 so the output should be four one two 

#include<iostream>
using namespace std;

// printing numbers
// use recursion
int breaks(int num, string arr[]){
    if(num==0){
        return 0;
    }
    int rem = num%10;
    num = num /10 ;
    breaks(num, arr);
    cout<<arr[rem]<<" ";
    return 0;
    
}

int main(){
    int num;
    cout<<"Enter the number"<<endl;
    cin>>num;
    string array[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    breaks(num,array);
    return 0;
}
