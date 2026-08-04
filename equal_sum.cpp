#include<iostream>
#include<vector>
using namespace std;

bool equalSum (vector<int> &nums){
    int totalSum = 0;
    int n = nums.size();
    for(int num : nums){
        totalSum+= num;
    }

        int leftSum =0;
        for(int i =0;i<n;i++){
            int rightSum = totalSum - leftSum - nums[i];

            if(leftSum == rightSum){
                return true;
            }
            leftSum += nums[i];
        }
        return false;
    
}

int main(){
    vector<int> nums = {1,5};
    if(equalSum(nums)){
        cout<<"true";
    }else{        cout<<"false";
    }

    return 0;
}