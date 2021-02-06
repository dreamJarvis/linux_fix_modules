// Find the repeating and the missing number in an read only array.
#include <bits/stdc++.h>
using namespace std;

// space complexity : O(n)
// time complexity  : O(n)
vector<int> repeatingArray(vector<int> &arr){
    int n = arr.size();

    unordered_map<int, int> storage;
    int a = 0, sum = 0;
    for(auto val:arr){
        if(storage.count(val)){
            a = val;
        }
        storage[val] = 1;
        sum += val;
    }
    int totalSum = (n*(n+1))/2;
    sum -= a;
    int b = totalSum - sum;

    return (vector<int> ({a, b}));
}

// using 2 equations
/*
    SumN = 1 + 2 + 3 + … + N = (N * (N + 1)) / 2
    And, let the sum of all the array elements be Sum. Now,
    SumN = Sum – A + B
    A – B = Sum – SumN …(equation 1)

    SumSqN = 12 + 22 + 32 + … + N2 = (N * (N + 1) * (2 * n + 1)) / 6
    And, let the sum of the squares of all the array elements be SumSq. Now,
    SumSq = SumSqN + A2 – B2
    SumSq – SumSqN = (A + B) * (A – B) …(equation 2)

    B = (((SumSq – SumSqN) / (Sum – SumN)) + SumN – Sum) / 2
    And, A = Sum – SumN + B
*/
// time complexity : O(n)
// space complexity : O(1)
vector<int> repeatingArray2(vector<int> &arr){
    int n = arr.size();
    // sum of 1st n natural numbers
    int sumN = (n*(n+1))/2;

    // sum of squares of 1st n natural numbers
    int sumSqN = (n*(n+1)*(2*n+1))/6;

    // to store the sum and sum of squares of the array elements
    int sum = 0, sumSq = 0;
    for(int i = 0;i < n; i++){
        sum += arr[i];
        sumSq = sumSq + (pow(arr[i], 2));
    }

    // these are the 2 equations that after solving we get the value of a , b
    int b = ( ( (sumSq - sumSqN)/(sum - sumN) ) + sumN - sum )/2;
    int a = sum - sumN + b;

    return (vector<int>({a, b}));
}

// using XOR method


//
void repeatingAndMissing(vector<int> &arr){
    int n = arr.size();

    cout << n << endl;

    int p=0, s=arr[0];

    for(int i = 1; i < n; i++)  s ^= arr[i];
    for(int i = 1; i <= n; i++)  p ^= i;

    int x = p^s;
    cout << x << endl;

    int rightmostBit = x & ~(x-1);
    cout << rightmostBit << endl;

    int a=0, b=0;
    for(int i = 0; i < n; i++){
        if(arr[i] & rightmostBit)   a ^= arr[i];
        else                        b ^= arr[i];
    }

    int t1 = p ^ (a ^ b);
    cout << t1 << endl;
    int t2 = x^t1;

    // cout << t1 << " " << t2 << endl;
}

// Driver function
int main(){
    //  1, 2, 2, 3, 4
    vector<int> arr({3, 1, 2, 5, 3});
    // vector<int> arr({ 1, 2, 2, 3, 4 });
    //
    // for(auto val:repeatingArray2(arr))
    //     cout << val << " ";
    // cout << endl;

    repeatingAndMissing(arr);

    return 0;
}
