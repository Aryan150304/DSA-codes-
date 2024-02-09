// we use Dutch national flag algorithm approach 
/*
We make three pointer 
low  = 0
mid  = 0
high  =  n-1
we traverse from mid to high and if we find 1 and then ignore if find 0 then swap with low else swap with high
We have to sort in such a way that 0 remain in starting 1 in mid and 2 in last
*/

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low = 0;
        int high = arr.size()-1;
        int mid = 0;
        while(high>=mid){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid]==2){
                 swap(arr[mid],arr[high]);
                 cout<<arr[high]<<" "<<high<<endl;
                 high--;
            }
            else{
                mid++;
            }
        }

    }
};
