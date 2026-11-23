#include<iostream>
#include<vector>
using namespace std;
int singleElement(vector<int> &nums){

    int n = nums.size()-1;
    int low =0;
    int high = n-1;
    if(n==1){
        return nums[0];
    }
    while(low < high){
        int mid = low + (high -low)/2;
        //make mid even
        if(mid %2==1){
            mid--;
        }
        if(nums[mid]==nums[mid+1]){
            low = mid +2;
        }else{
            high = mid;
        }
    }
    return nums[low];
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<singleElement(nums)<<endl;
    return 0;
}