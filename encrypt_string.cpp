#include<iostream>
#include<string>

using namespace std;

string encrypteString(string s){
    int temp = " ";
    int n = s.size();
    for(int i =0;i<n;i++){
        char ch =s[i];
        int count = 0;

        while(i<n && s[i == ch]){
            count ++;
            i++;
        }
        i--;

    temp +=ch;
    temp += to_string(count);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int main(){
    string s = "aabc";
    cout<<encrypteString(s)<<endl;
    return 0;
}