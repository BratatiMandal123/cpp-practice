#include<iostream>
#include<vector>
using namespace std;
pair<int,int> getFloorAndCeil(vector<int> &arr, int x){
    int low = 0;
    int high = arr.size()-1;
    int floor = -1;
    int ceil = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == x){
            floor = arr[mid];
            ceil = arr[mid];
            break;
        }else if(arr[mid]<x){
            floor = arr[mid];
            low = mid+1;
        }else{
            ceil = arr[mid];
            high = mid -1;
        }
    }
    return {floor,ceil};
}
int main(){
    int x;
    cin>>x;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pair<int,int>ans = getFloorAndCeil(arr,x);
    cout<<"Floor : "<<ans.first<<endl;
    cout<<"Ceil : "<<ans.second<<endl;
    return 0;
}