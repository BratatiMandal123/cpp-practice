#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool possible(vector<int> &nums, int day, int m, int k){
    int count =0;
    int bouquet = 0;

    for(int i =0;i<nums.size();i++){
        if(nums[i]<=day){
            count++;
            if(count ==k){
                bouquet++;
                count =0;
            }
        }else{
            count =0;
        }
    }
    return bouquet>=m;

}

int minDays(vector<int> &nums, int m,int k){
    int n = nums.size()-1;
    if((long long)m*k>n){
        return -1;
    }
    int ans = -1;
    int low = *min_element(nums.begin(),nums.end());
    int high = *max_element(nums.begin(),nums.end());
    while(low<=high){
        int mid = low +(high - low)/2;

        if(possible(nums,mid,m,k)){
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
    int m,k;
    cin>>m>>k;
    cout<<minDays(nums,m,k)<<endl;
    return 0;
}