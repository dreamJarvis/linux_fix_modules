// Find the two repeating elements in a given array
/*
    You are given an array of n+2 elements. All elements of the array are in range 1 to n. And all elements occur once except two numbers which occur twice. Find the two repeating numbers.
    For example, array = {4, 2, 4, 5, 2, 3, 1} and n = 5

    The above array has n + 2 = 7 elements with all elements occurring once except 2 and 4 which occur twice. So the output should be 4 2.
*/
#include <bits/stdc++.h>
using namespace std;

// time : O(nlong(n))
// space : O(1)
void repeatingElements(vector<int> &arr){
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int x = arr[0];
    for(int i = 1; i < n; i++){
        if(x == arr[i])
            cout << x << " ";
        x = arr[i];
    }
}

// time : O(n)
// space : O(n)
void repeatingElements2(vector<int> &arr){
    int n = arr.size();

    unordered_map<int, bool> elements;

    for(auto value:arr){
        if(elements.count(value))
            cout << value << " ";
        else    elements[value] = true;
    }
}

// using XOR, without modifying the orignial array
// time complexity  : O(n)
// space complexity : O(1)
void repeatingElementsXOR(vector<int> &arr){
    int Xor = arr[0];
    int n = arr.size();
    int originSize = n - 2;

    // getting the xor of all the elements in the arr and 1-->n
    // we will be left wiht the XOR of repeating elements
    for(int i = 1; i < n; i++)  Xor ^= arr[i];
    for(int i = 1; i <= originSize; i++) Xor ^= i;

    // ---- get the rightmost bit ------- //
    // ~(Xor-1) --> 2's complement of Xor
    // Take two's complement of the given no as all bits are reverted except the first '1' from right to left
    // and Xor & (Xor 2's complement) == rightmost set bit
    //** gfg link for finding rightmost set bit : https://www.geeksforgeeks.org/position-of-rightmost-set-bit/
    int setRightBit = Xor & ~(Xor-1);

    // dividing the array into 2 sub-parts, one whose bit at the rightmostBit position is set, othrs whose isn't
    // and good thing is, all because all the repeating element will correspond to the same rightmostBit, i.e. they will be stored at the same side
    // and both of the number will be stored at different sides, that is the reason why we seperate the array on the basis of rightmostBit, which is the right most Bit of xor of these 2 repeating/missing elements
    // so if one of the repeating/missing element is on one side , then the missing/repeating element will be on the other side
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] & setRightBit)   a ^= arr[i];
        else                        b ^= arr[i];
    }

    // now we have the a == xor of all the elements whose bit are set at the setRightBit position
    // and b == xor of all the elements whose bit are not set at the setRightBit position
    // now if we xor a with all the elements whose setRightBit is set from 1-->n, then we will get the element that is missing from the original array, because the number that is missing is either a repeating element or is missing, if it is either of those then we will get the element
    for(int i = 1; i <= originSize; i++){
        if(i & setRightBit)    a ^= i;
        else                    b ^= i;
    }

    cout << a << " " << b << endl;
}

// making 2 equations
// time complexity  : O(n)
// space complexity : O(1)
// returns the factorial of n
int fact(int n){ return (n==0) ? 1 : n*fact(n-1); }

void repeatingElementsEquation(vector<int> &arr){
    int s = 0;  //  sum of elements in array
    int p = 1;  //  product of elements in array
    int x, y;   // repeating elements
    int d;      // difference of x and y, i.e. x - y
    int size = arr.size();
    int n = size - 2;

    // calculate sum and product of all elements in the array
    for(int i = 0; i < size; i++){
        s += arr[i];
        p *= arr[i];
    }

    s -= n*(n+1)/2;         //  s is now x + y
    p /= fact(n);           //  p is now x*y

    d = sqrt(s*s - 4*p);    // d is x - y now

    x = (d + s)/2;          //  gives us x
    y = (s - d)/2;          //  gives us y

    cout << x << " " << y << endl;
}

// ======================= modifies the original array ========================
// time : O(n)
// space : O(1)
void repeatingElements3(vector<int> &arr){
    int n = arr.size();

    int x1 = arr[0];
    int x2 = 1;

    for(int i = 1; i < n; i++)      x1 ^= arr[i];
    for(int i = 2; i <= n+2; i++)    x2 ^= i;

    x1 ^= x2;

    int a = 0, i = 0;
    while(arr[i] != -1){
        a = arr[i];
        arr[i] = -1;
        i = a;
    }

    cout << a << " " << (a^x1) << endl;
}

// using array element as index
// time : O(n)
// space : O(1)
void repeatingElements4(vector<int> &arr){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        if(arr[abs(arr[i])] > 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << " ";
    }
}

// Driver funtion
int main(){
    vector<int> arr({4, 2, 4, 5, 2, 3, 1});
    // vector<int> arr2(arr.size());
    // arr2 = arr;
    //
    // repeatingElements(arr);
    // cout << "\n";
    // repeatingElements2(arr);
    // cout << "\n";
    // repeatingElements3(arr);
    // cout << "\n";
    // repeatingElements4(arr2);

    // repeatingElementsXOR(arr);
    repeatingElementsEquation(arr);

    return 0;
}
