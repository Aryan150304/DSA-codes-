
#include<iostream>
using namespace std;

void sortarr(int *arr, int n , int i){
    if(i>=n-1){
        return ;
    }
    int minIndex = i ;
    for(int j =i+1;j<n;j++){
        if(arr[j]<arr[minIndex]){
            minIndex =j;
        }
    }
    swap(arr[minIndex],arr[i]);
    sortarr(arr,n,i+1);
}
int main(){
    int arr[5]={10,9,8,7,0};
    sortarr(arr,5,0);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
