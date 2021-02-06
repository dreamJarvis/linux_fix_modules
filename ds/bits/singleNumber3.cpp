// leetcode : 260. Single Number III
#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int sum = nums[0];
    int n = nums.size();
    for(int i = 1; i < n; i++){
        sum ^= nums[i];
    }

    int rightMostSetBit = sum & (~(sum-1));

    int leftSum = 0, rightSum = 0;
    for(int i = 0; i < n; i++){
        if(rightMostSetBit & nums[i])    leftSum ^= nums[i];
        else                            rightSum ^= nums[i];
    }

    return vector<int>({leftSum, rightSum});
}

vector<int> singleNumber(vector<int>& nums) {
    std::vector<int> res;
    int var=0;
    for(int i: nums)
    {
        var = var ^ i;
    }

    int temp = var;
    int a =1;

    // finding right-most bit
    while(1)
    {
        if (temp & a)
            break;
        else
            a<<=1;
    }


    int num1 =0,num2 =0;
    for(int i: nums)
    {
        if (i & a) num1= num1 ^ i;
    }

    res.push_back(num1);
    res.push_back(var ^ num1);
    return res;
}

// Driver function
int main(){
    vector<int> nums({1, 2, 1, 3, 2, 5});

    for(auto item:singleNumber(nums))
        cout << item << " ";
    cout << endl;

    return 0;
}
