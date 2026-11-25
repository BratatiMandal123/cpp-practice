#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int calculateHours(vector<int> &nums, int mid){
    int totalHours = 0;
    for(int i=0;i<nums.size();i++){
        totalHours+= ceil((double)(nums[i])/(double)(mid));
    }
    return totalHours;
}

int minEatingSpeed(vector<int>&nums, int h){
    int low = 1;
    int high = *max_element(nums.begin(),nums.end());
    int ans = high;
    while(low<=high){
        int mid = low +(high - low)/2;
        int totalHours = calculateHours(nums,mid);
        if(totalHours<=h){
            ans = mid;
            high = mid-1;

        }else{
            low = mid +1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int h;
    cin>>h;
    cout<<minEatingSpeed(nums,h);
    return 0;
}