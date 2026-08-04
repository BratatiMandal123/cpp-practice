#include <iostream>
#include <vector>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int target){
    int left = 0;
    int sum = 0;

    for(int right = 0;right< arr.size(); right++){
        sum+= arr[right];

        while(sum > target){
            sum-= arr[left];
            left++;
        }

        if(sum==target){
            return{left+1, right+1};
        }

    }
    return {-1,-1};
}

int main(){
    vector<int> arr = {1,3,4};
    int target = 2;
    vector<int> ans = subarraySum(arr,target);
    cout<<ans[0] <<" "<<ans[1]<<endl;

    return 0;
}