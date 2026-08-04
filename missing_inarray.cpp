#include<iostream>
#include<vector>
using namespace std;

vector<int> missingArray(vector<int> &arr){
    int n = arr.size()+1;
    long long expected = 1ll*n*(n+1)/2;

    long long actual = 0;
    for(int num : arr){
        actual += num;
    }
    int ans = expected - actual;
    return {ans} ;
}

int main(){
    vector<int> arr={1,2,3,5};
    vector<int> missing = missingArray(arr);
    cout<<"Missing Number is "<<missing[0]<<endl;

    return 0;
}