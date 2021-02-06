#include <bits/stdc++.h>
using namespace std;

// optimise the solution
int stallServed(vector<int> &arr, int n){
    int vikas = 0;

    int i = 0;
    while(arr[i] != 0){
        arr[i] -= vikas;
        i = (i+1)%n;
        vikas++;
    }

    return vikas;

    // // int val = arr[0], index = 0;
    // // for(int i = 0; i < n; i++)
    // //     if(arr[i] <= val)
    // //         index = i;
    //
    // for(int i = 1; i <= n; i++)
    //     arr[i-1] = arr[i-1]/i;
    //
    // int index = 0, temp = arr[0];
    // for(int i = 1; i < n; i++){
    //     if(arr[i] <= temp){
    //         index  = i;
    //         temp = arr[i];
    //     }
    // }
    //
    // return index;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int size;
        cin >> size;

        vector<int> stalls;
        int temp = 0;
        for(int  j =0; j < size; j++){
            cin >> temp;
            stalls.push_back(temp);
        }

        cout << stallServed(stalls, stalls.size()) << endl;
    }
}
