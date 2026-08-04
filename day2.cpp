#include<iostream>
#include<vector>
using namespace std;
 struct Transaction{
    string sender,receiver;
    double amount;
    long long time;
 };
 
 int main(){
    int n ;
    cout<<"Enter the size of an array";
    cin>>n;
    vector<int>Transaction(n);

    for(int i=0;i<n;i++){
        cin>>t[i].sender>>t[i].receiver>>t[i].amount>>t[i].time;
    }

    vector<int>fraud(n,false);
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(t[i].sender ==t[j].sender &&
            t[i].receiver==t[j].receiver &&
            t[i].amount == t[j].amount &&
            abs(t[i].time - t[j].time <=60)){
                fraud[i]= true;
                fraud[j]= true;
            }
        }
    }
 }


