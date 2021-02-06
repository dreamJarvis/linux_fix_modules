/*
    C++ program to print all palindromic partitions of a given string
    https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/
*/
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int low, int high){
    while(low < high){
        if(str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void util(string str, int start, vector<vector<string>> &result, vector<string> &currPalindrome){
    if(start >= str.length()){
        result.push_back(currPalindrome);
    }

    for(int i = start ; i < str.length(); i++){
        if(isPalindrome(str, start, i)){
            currPalindrome.push_back(str.substr(start, i-start+1));

            util(str, i+1, result, currPalindrome);

            currPalindrome.pop_back();  // back-tracking
        }
    }
}

vector<vector<string>> palindromicPartitioning(string str){
    vector<vector<string>> result;
    vector<string> currPalindrome;

    util(str, 0, result, currPalindrome);
    return result;
}

// Driver program
int main(){
	string str = "nitin";

    for(auto &i:palindromicPartitioning(str)){
        for(auto &j:i)
            cout << j << " ";
        cout << endl;
    }

	return 0;
}
