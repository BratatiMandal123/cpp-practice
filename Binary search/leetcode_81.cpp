#include<iostream>
#include<vector>
using namespace std;
bool search(vector<int>&nums,int target){

    int low = 0;
    int high = nums.size()-1;
    while(low<=high){

        int mid = low + (high - low)/2;

        if(nums[mid]==target){
            return true;
        }
        // handle duplicates
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
        }
        //check for left sorted
        else if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target <nums[mid]){
                high = mid -1;
            }else{
                low = mid +1;
            }
        }else{
            if(nums[mid]<target && target<= nums[high]){
                low = mid +1;
            }else{
                high = mid -1;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;
    if(search(nums, target)){
        cout<<"True"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}