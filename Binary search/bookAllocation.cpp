#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canAllocate(vector<int> nums, int m,int pages){
    int student =1;
    int pageAllocated = 0;
    for(int i=0;i<nums.size();i++){
        if(pageAllocated + nums[i]<=pages){
            pageAllocated+=nums[i];
        }else{
            student++;
            pageAllocated = nums[i];
        }
    }
    return student<=m;
}

int bookAllocation(vector<int> &nums, int m){
    int n = nums.size();
    if(m >n) return -1;
    int low = *max_element(nums.begin(),nums.end());
    int high=0;
    for(int i=0;i<n;i++){
        high+=nums[i];
    }
    int ans= -1;
    while(low<=high){
        int mid = low +(high - low);
        if(canAllocate(nums,m,mid)){
            ans = mid;
            high = mid -1;
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
    int m;
    cin>>m;
    cout<<bookAllocation(nums,m);
    return 0;

}