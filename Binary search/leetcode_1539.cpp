#include<iostream>
#include<vector>
using namespace std;
int kthMissing(vector<int> &nums, int k){
    int low =0;
    int high = nums.size()-1;
    while(low<=high){
        int mid = low +(high - low)/2;
        int missing = nums[mid] -(mid+1);
        if(missing < k){
            low = mid+1;
        }else{
            high = mid -1;
        }
    }
    return low + k;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    cout<<kthMissing(nums, k)<<endl;
    return 0;
}