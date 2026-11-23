#include<iostream>
#include<vector>
using namespace std;
int minSorted(vector<int> &nums){
    int low = 0;
    int high = nums.size()-1;
    while(low < high){
        int mid = low +(high - low)/2;
        if(nums[mid] >nums[high]){
            low = mid +1;
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
    cout<<minSorted(nums)<<endl;
    
    return 0;
}