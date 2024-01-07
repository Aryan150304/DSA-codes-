#include<iostream>
using namespace std;

void merge(int *arr, int start, int end){
    int mid = (start+end)/2;
    int len1 = (mid-start)+1;
    int len2 = end - mid ;
    
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    
    // setting the values
    for(int i=0;i<len1;i++){
        arr1[i]=arr[i+start];
    }
    
     for(int i=0;i<len2;i++){
         arr2[i] = arr[i+mid+1];
    }
    
    
    // comparison 
    int i =0;
    int j = 0;
    int mainIndex = start;
    
    
    
    while(i<len1&&j<len2){
        if(arr1[i]<=arr2[j]){
            arr[mainIndex++]=arr1[i++];
        }
        else{
            arr[mainIndex++]=arr2[j++];
        }
    }
    while(i<len1){
        arr[mainIndex++]=arr1[i++];
    }
     while(j<len2){
        arr[mainIndex++]=arr2[j++];
    }
    
    delete []arr1;
    delete []arr2;
}





void mergeSort(int *arr, int start, int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end);
}

int main(){
    int arr[5]={10,9,8,7,0};
        mergeSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    
}
