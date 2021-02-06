/*
    8. Max sum in the configuration
    https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/0/?track=amazon-arrays&batchId=192
*/
#include <bits/stdc++.h>
using namespace std;

// O(N)
int max_sum(int A[],int N){
    // total sum of all the elements with their indexes
    int totalSum = 0;
    for(int i = 0; i < N; i++)
        totalSum += A[i]*i;

    // sum of just the elements
    int sumOfVal = 0;
    for(int i = 0; i < N; i++)
        sumOfVal += A[i];

    int maxSum = totalSum;
    int nextSum = 0;
    for(int i = 1; i < N; i++){
        nextSum = totalSum - (sumOfVal - A[i-1]) + A[i-1]*(N-1);
        totalSum = nextSum;
        maxSum = max(maxSum, nextSum);
    }

    return maxSum;
}

int main(){
    int A[] = {8, 3, 1, 2};
    int n = sizeof(A)/sizeof(A[0]);

    cout << max_sum(A, n) << endl;

    return 0;
}
