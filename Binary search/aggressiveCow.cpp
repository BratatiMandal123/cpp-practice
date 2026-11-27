#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canPlace(vector<int> &stall, int k, int dist){
    int cows = 1;
    int lastposition = stall[0];
    for(int i=0;i<stall.size();i++){
        if(stall[i] - lastposition>=dist){
            cows++;
            lastposition = stall[i];
        }
        if(cows>=k){
            return true;
        }
    }
}

int aggressiveCows(vector<int> &stall,int k){
    int n = stall.size();
    sort(stall.begin(),stall.end());
    int low = 1;
    int high = stall[n-1]-stall[0];
    int ans= 0;

    while(low<=high){
        int mid = low+(high- low)/2;
        if(canPlace(stall,k,mid)){
            ans = mid;
            low = mid+1;
        }else{
            high = mid -1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>stall(n);
    for(int i=0;i<n;i++){
        cin>>stall[i];
    }
    int k;
    cin>>k;
    cout<<aggressiveCows(stall,k)<<endl;
    return 0;
}
