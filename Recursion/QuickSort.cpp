
#include <iostream>
using namespace std;

int partioning(int *arr, int start, int end){
    int pivot = arr[start];
    int smallelem = 0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<pivot){
            smallelem++;
        }
    }
    int pivotIndex = start+smallelem;
    // before returing partially sort the array and swap the pivot to its right place 
    swap(arr[start],arr[pivotIndex]);
    pivot = arr[pivotIndex];
    int i = start;
    int j = end;
    while(j>=i){
        if(arr[i]>pivot&&arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        else if(arr[i]<pivot){
            i++;
        }
        else{
            j--;
        }
    }
    return pivotIndex;
    
}

void quicSort(int *arr, int start, int end){
    if(start>=end){
        return ;
    }
    int pivotIndex = partioning(arr,start,end);
    quicSort(arr,start,pivotIndex-1);
    quicSort(arr,pivotIndex+1,end);
    
}

int main()
{
    int arr[5]={1,20,6,4,3};
    int pivot = arr[0];
    quicSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
