#include<iostream>
#include<vector>
using namespace std;

int firstOccurrance(vector<int> &nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int ans =-1;
    while(low <=high){
        int mid = low +(high - low)/2;
        if(nums[mid]==target){
            ans = mid;
            high = mid-1;
        }else if(nums[mid]<target){
            low = mid +1;
        }else{
            high = mid -1;
        }
    }
    return ans;
}
int lastOccurrance (vector<int> &nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;

        if(nums[mid]==target){
            ans = mid;
            low = mid +1;
        }else if(nums[mid]<target){
            low = mid +1;
        }else{
            high = mid -1;
        }
    }
    return ans;


}
int countOccurrance(vector<int> &nums, int target){
    int first = firstOccurrance(nums, target);
    if(first ==-1){
        return 0;
    }
    int last = lastOccurrance(nums, target);
    return last - first +1;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    int target;
    cin>>target;
    cout<<countOccurrance(nums, target)<<endl;
    return 0;
}