#include<iostream>
#include<vector>
using namespace std;
int firstOccurance(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int ans =-1;
    while(low<=high){
        int mid= low +(high - low)/2;
        if(nums[mid]==target){
            ans = mid;
            high = mid -1;

        }else if(nums[mid]<target){
            low = mid +1;

        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int lastOccurance(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int ans= -1;
    while(low<=high){
        int mid = low +(high -low)/2;
        if(nums[mid]==target){
            ans = mid;
            low = mid +1;
        }else if(nums[mid]< target){
            low = mid +1;
        }else{
            high = mid -1;
        }
    }
    return ans;

}
int main(){
    int target;
    cin>>target;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int first = firstOccurance(nums, target);
    int last = lastOccurance(nums, target);
    cout<<"["<<first<<","<<last<<"]"<<endl;
    return 0;
}