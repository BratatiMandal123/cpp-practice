#include<iostream>
#include<string>

using namespace std;

char getMaxOccuringChar(string s){
    int freq[26] = {0};

    for(char ch :s){
        freq[ch-'a']++;

    }
    int maxfreq = 0;
    int ans =0;

    for(int i =0;i<26;i++){
        if(freq[i]> maxfreq){
            maxfreq = freq[i];
            ans = i+'a';

        }
    }
    return ans;

}

int main(){
    string s = "output";
    cout<<getMaxOccuringChar(s)<<endl;

    return 0;
}