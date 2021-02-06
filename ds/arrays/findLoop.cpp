// to find the loop in the array
#include <bits/stdc++.h>
using namespace std;

bool detectloop(vector<int> &arr){
    int ptr_1 = 0, ptr_2 = 2;
    for(int i = 0; i < arr.size(); i++){
        if(arr[ptr_1] == arr[ptr_2])
            return true;
        ptr_1++;
        ptr_2+=2;
    }
    return false;
}

// Driver function
int main(){
    vector<int> arr{1, 2, -1, 3, 1, 5};
    cout << detectloop(arr) << endl;
    return 0;
}
