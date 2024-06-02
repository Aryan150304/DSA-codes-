// Longest subarray with sum = K
/* 
First approach - PREFIX SUM
Start iterating from index =0 and find the sum if the sum == K then find the maxlength 
else there can exist a subarray in that array whose sum ==K 
Make a hashmap and store the sum and their index , if the sum previously exist then do not update as we want the left most value to find the
largest subarray
for every sum find sum - K if sum-K exist then there exist an array with sum = K
*/

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int K) 
    { 
        map<long,int> map;
        int maxlen =0;
        int sum =0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
            if(sum==K){
                maxlen = max(maxlen,i+1);
            }
            else if(map.find(sum-K)!=map.end()){
                // then tehre exist K 
                int index = map[sum-K];
                maxlen = max(maxlen,i-index);
            }
            // now store the sum
            if(map.find(sum)==map.end()){
                map[sum] =i;
            }
        }
        return maxlen;
    } 
};
