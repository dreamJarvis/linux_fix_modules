/*
    To find the median of 2 sorted arrays
    leetcode : https://leetcode.com/problems/median-of-two-sorted-arrays/
    source : https://www.youtube.com/watch?v=LPFhl65R7ww
*/
#include <bits/stdc++.h>
using namespace std;

double medianOf2SortedArrays(vector<int> &input_1, vector<int> &input_2){
    if(input_1.size() > input_2.size())
        return medianOf2SortedArrays(input_2, input_1);

    int x = input_1.size();
    int y = input_2.size();

    int low = 0;
    int high = x;

    while(low <= high){
        int partitionX = (low + high)/2;
        int partitionY = (x+y+1)/2 - partitionX;

        // considering the edge cases : for input_1
        // if partition is 0, it means nothing is there on left side. Use INT_MIN for maxLeftX
        // if pasrtiton is length of input, then there is nothing on the right side. Use INT_MAX for minRight
        int maxLeftX = partitionX == 0 ? INT_MIN: input_1[partitionX-1];
        int minRightX = partitionX == x ? INT_MAX: input_1[partitionX];

        // edge cases for input_2 : same as input_1
        int maxLeftY = partitionY == 0 ? INT_MIN : input_2[partitionY-1];
        int minRightY = partitionY == y ? INT_MAX : input_2[partitionY];

        if(maxLeftX <= minRightY && maxLeftY <= minRightX){
            // if this condition is true, it means we have partitioned the array at correct place
            // Now get max of left elements and min of right elements to get the median in case of total even numbr of elements.
            // else get the max of right elements in odd number of elements
            if((x+y)%2==0)  return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY));
            else            return (max(maxLeftX,maxLeftY));
        }
        else if(maxLeftX > minRightY)   high = partitionX - 1;
        else                            low = partitionX;
    }

    // error detected
    return -1;
}

// Driver function
int main(){
    vector<int> x({1, 3, 8, 9, 15, 23});
    vector<int> y({7, 11, 19, 21, 18, 25});

    cout << (double)medianOf2SortedArrays(x, y) << endl;

    return 0;
}
