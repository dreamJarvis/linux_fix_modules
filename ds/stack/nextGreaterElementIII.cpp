// 556. Next Greater Element III
#include <bits/stdc++.h>
using namespace std;

// helper function : converts string to integer
int strToInt(string str){
    stringstream ss(str);
    int num;
    ss >> num;
    return num;
}

// tc : O(n + m),  m -- elements in stack
/*
    prerequisite : to find next smaller number from back

    logic:
    as we have to find the just next Greater number ,
    we can use the technique which is used to find the next greater Element in an given array..

    so we have to find the next greater number, as we know the power of 10 increases as we move from right --> left.
    .'. if we want to find the just greater Element we can start by swapping number fom the rear end..
    i.e. we find the next smaller from the rear..

    i starts from n-1
    i.e. if arr[i] < arr[i+1], then swap them, because by doing so we will have a greater number, as the decimal power of element at i'th index > (i+1)'th index,
    so by swappind the i'th index element with a greater element we are just increasing the number.

    so now when we have swapped the number , as we have to find just greater number from given number num,
    we will sort the acquired number after swapping , to give us the smallest number with larger (i+t)'th index number still in its poistion ,
    so we will sort from (i+1+1)'th --> n'th index, this will give us the smallest denomination of this combination

    after doing so, we will swap the elements back, because we can find still smaller denomination number greater the num
*/
int nextGreaterElement(int num) {
    string str = to_string(n);
    int N = str.size();

    stack<int> s;
    int nextMin = INT_MAX;

    for(int i = N-1; i >= 0; i--){
        if(i == N-1 || s.empty()){
            s.push(i);
        }

        // this loop starts when it find an number greater then the nubber at top of stack
        while(!s.empty() && str[i] < str[s.top()]){
            swap(str[i], str[s.top()]);

            // we will check if by swapping we get a number that is greater then num
            int temp = strToInt(str);
            if(temp > n){
                string p = str;
                sort(p.begin()+i+1, p.end());           // sort to get smallest possible denomination
                nextMin = min(nextMin, strToInt(p));    // stores the smallest of all possibility , which is greater then num
            }

            // we swap back to bring string to its original form
            swap(str[i], str[s.top()]);
            s.pop();        // we will swap with every number greater then the i'th index number
        }

        s.push(i);
    }

    return nextMin == INT_MAX ? -1 : nextMin;
}

// Driver function
int main(){
    int num = 21;
    // int num = 230241;
    // int num = 1253;
    // int num = 12443322;

    cout << nextGreaterElement(num) << endl;

    return 0;
}
/*
230241

12443322 - 13222344
*/
