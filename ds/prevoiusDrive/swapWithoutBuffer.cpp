// swap 2 numbers without using buffer
#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y){
    x = x^y;
    y = x^y;
    x = x^y;
    return ;
}

// Driver function
int main(){
    vector<int> arr({1, 2, 3, 4, 5});
    for(int i = 0; i < arr.size()-1; i++)
        swap(arr[i], arr[i+1]);

    for(auto i:arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
