// problem statement - The array consist of only 2 values 0 and 1 sort the array in non decreasing order in o(n) complexity.

// Solution - */ 

#include<iostream>
using namespace std ;
void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sort01(int *arr, int n){
    int i = 0;
    int j = n -1 ;
    while(i<=j){
        if(arr[i]==0){
            i++;
        }
        else if(arr[j]==1){
            j--;
        }
        else{
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    printArray(arr,n);
}

int main(){
    int arr[10]={0,0,1,1,0,0,1,1,0,0};
    cout<<"Array before sorting"<<endl;
    printArray(arr,10);
    cout<<"Array after sorting"<<endl;
    sort01(arr,10);
    
}
// here we use the 2 pointer approach using i and j .
// similar problem -  https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055
