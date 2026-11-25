#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int sumById(vector<int> &nums, int div){
    int sum = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        sum= sum + ceil((double)(nums[i])/ (double)(div));
    }
    return sum;
}

int smallestDiv(vector<int>&nums, int threshold){
    int low =1;
    int high = *max_element(nums.begin(),nums.end());
    while(low<=high){
        int mid = low+(high - low)/2;
        if(sumById(nums, mid)<=threshold){
            high = mid -1;
        }else{
            low = mid+1;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int threshold;
    cin>>threshold;
    cout<<smallestDiv(nums,threshold);
    return 0;

}