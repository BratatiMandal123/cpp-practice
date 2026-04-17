#include<iostream>
#include <numeric>
using namespace std;
template<size_t N>


double average(const int (&arr)[N]){
    return accumulate(*&arr, *&arr + N, 0.0) / N;

}
int main(){
    //Test Cases
    int arr1[]={1,2,3,4,5};
    cout<<"Test 1:"<<average(arr1)<<endl;
    int arr2[]={1,2,1,1,5,1};
    cout<<"Test 2:"<<average(arr2)<<endl;
    return 0;
}