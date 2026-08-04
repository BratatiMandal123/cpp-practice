#include<iostream>
#include<vector>
using namespace std;

int cnt =0;
void solve(vector<int>&arr, int pos, int N, int end, vector<int>&values){
    if(pos ==N){
        for(int x: arr)
          cout<<x;
        cout<<endl;
        cnt++;
        return;
    }
    for(int val:values){
        if(val == arr[pos-1])
           continue;
        
        if(pos == N-1){
            if(val!= end)
              continue;
        }
        arr[pos] =val;
        solve(arr,pos +1, N, end, values);
    }
}

int main(){
    int N = 4;
    int end =3;
    vector<int> values= {1,2,3,4};
    vector<int>arr(N);

    arr[0] =1;
    solve(arr, 1,N,end,values);

    cout<<"total arrangements = "<<cnt;
    return 0;
}