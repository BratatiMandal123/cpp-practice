#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canShip(vector<int>&nums, int capacity, int days){
    int day = 1;
    int currentLoad = 0;
    for(int i=0;i<nums.size();i++){
        if(currentLoad + nums[i]<=capacity){
            currentLoad += nums[i];
        }else{
            day++;
            currentLoad = nums[i];
        }
    }
    return day<=days;
}

int shipWithDays(vector<int> &nums, int days){
    int low = *max_element(nums.begin(), nums.end());
    int high =0;
    int ans= high;
    for(int i=0;i<nums.size();i++){
        high+=nums[i];
    }
    while(low<=high){
        int mid = low+(high - low)/2;
        if(canShip(nums,mid,days)){
            ans = mid;
            high = mid-1;

        }else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    int n ;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int days;
    cin>>days;
    cout<<shipWithDays(nums, days)<<endl;
    return 0;
}