#include<iostream>
#include<vector>
using namespace std;

int circularSubarraySum(vector<int> &arr){
    int totalSum =0;
    int currMax =arr[0];
    int maxSum =arr[0];
    int currMin =arr[0];
    int minSum =arr[0];

    for(int i =1;i< arr.size();i++){
        currMax = max(arr[i], currMax + arr[i]);
        maxSum = max(maxSum , currMax);

        currMin = min(arr[i], currMin + arr[i]);
        minSum = min(minSum, currMin);

        totalSum+= arr[i];
    }

    totalSum+= arr[0];
    if(maxSum <0)
        return maxSum;
    
    return max(maxSum, totalSum - minSum);
}

int main(){
    vector<int> arr={ 8,-8,9,-9,10,-11,12};
    int ans = circularSubarraySum(arr);
    cout<<"Maximum circular subarray sum is "<<ans<<endl;
    
    return 0;
}