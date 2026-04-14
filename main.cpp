#include <iostream>
#include <string>
using namespace std;


char maxOccurringChar(string s) {
    /* freq array of 256 size for strong each character frequncy
    * need an for loop to traverse the string and store each character in the freq array for
    calculating frequency
    * now find the character with maximum frequency from the string by comparing
    
    */
   if( s.empty()) throw invalid_argument("Input string cannot be null or empty");
    int freq[256] = {0};// an array for storing ASCII character
    for(char ch : s){
        freq[ch]++;

    }
    //Find character with maximum frequncy

    int maxCount =0;
    char maxChar=s[0];
    for(int i =0;i<256;i++){
        if(freq[i]>maxCount){
            maxCount = freq[i];
            maxChar = (char)i;
        }
        
    }
    return maxChar;

    
}

int main() {
    // Test cases
    string s1 = "takeuforward";
    cout << "Test 1: " << maxOccurringChar(s1) << endl;

    string s2 = "apple";
    cout << "Test 2: " << maxOccurringChar(s2) << endl;

    string s3 = "hello world";
    cout << "Test 3: " << maxOccurringChar(s3) << endl;

    string s4 = "\0";
    cout << "Test 4: " << maxOccurringChar(s4) << endl;

    return 0;
}
