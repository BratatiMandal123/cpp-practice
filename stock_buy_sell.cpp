#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int> & prices){
    int minPrice =prices[0];
    int maxProfit= 0;

    for(int price:prices){
        minPrice = min(minPrice, price);
        int profit = price - minPrice;
        maxProfit = max(maxProfit, profit);
    }
    return maxProfit;
}

int main(){
    vector<int> prices={7,6,4,3,1};
    cout<<"Maximum profit: "<<maxProfit(prices)<<endl;
    return 0;
}