// 1295. Find Numbers with Even Number of Digits
#include <bits/stdc++.h>
using namespace std;

int findNumbers(vector<int>& nums) {
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        if(noOfDigits(nums[i])%2==0)
            count++;
    }

    return count;
}

int noOfDigits(int num){
    int count=0;
    while(num!=0){
        count++;
        num /=10;
    }

    return count;
}

// Driver function
int main(){

    return 0;
}
