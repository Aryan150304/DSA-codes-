// solving bubble sort using recursion 
#include <iostream>

using namespace std;
void sortArray (int *arr, int n){
    if(n==1){
        return ;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    n--;
    return sortArray(arr,n);
}

int main()
{
    int arr[5]={10,9,8,7,0};
    sortArray(arr,5);
    int n = 5 ;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
