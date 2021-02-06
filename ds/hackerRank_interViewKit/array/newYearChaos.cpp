// hackerRank : New Year Chaos
// approach : minimum swap to sort an unosorted consecutive array
#include <bits/stdc++.h>
using namespace std;

void minimumBribes(vector<int> q){
    int n = q.size();
    int swapCount = 0;

    for(int i = n-1; i >= 0; i--){
        if(q[i] != i+1){
            if(q[i-1] == (i+1)){
                swapCount++;
                swap(q[i], q[i-1]);
            }
            else if(q[i-2] == (i+1)){
                swapCount+=2;
                swap(q[i-2], q[i-1]);
                swap(q[i], q[i-1]);
            }
            else {
                cout << "Too chaotic" << endl;
                return ;
            }
        }
    }

    cout << swapCount << endl;
    return ;
}

int main(){
    vector<int> arr({2, 1, 5, 3, 4});
    // vector<int> arr({2, 5, 1, 3, 4});
    // vector<int> arr({1, 2, 5, 3, 7, 8, 6, 4});
    // vector<int> arr({5, 1, 2, 3, 7, 8, 6, 4});

    minimumBribes(arr);

    return 0;
}
/*
5 1 2 3 7 8 6 4
1 2 5 3 7 8 6 4
2 5 1 3 4
1 2 5 3 4 7 8 6
*/
