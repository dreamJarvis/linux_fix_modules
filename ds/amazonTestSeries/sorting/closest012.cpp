#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// O(n)
// O(1)
// void segragate012(int a[], int n){
//     int s = 0, e = n-1;
//     while(s<e){
//         while(s < e && a[s]==0){s++;}
//         if(a[s] && a[e]==0){
//             swap(a[s], a[e]);
//             s++;
//         }
//         e--;
//     }
//
//     s = 0;
//     while(s < n && !a[s]){s++;}
//
//     e = n;
//     while(s < e){
//         while(s < e && a[s]==1){s++;}
//         if(a[s]==2 && a[e]==1){
//             swap(a[s], a[e]);
//             s++;
//         }
//         e--;
//     }
//
//     return;
// }


// using 3-way partitioning --> dutch national flag problem
void segragate012(int a[], int n){
    int low = 0, mid = 0, high = n-1;
    while (mid <= high) {
        switch (a[mid]) {
            case 0:
                swap(a[low++], a[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(a[mid], a[high--]);
                break;
        }
    }

    return;
}

// Driver function
int main(){
    FIO;
    // int a[] = {0, 2, 1, 2, 0};
    // int a[] = {0, 1, 0};
    // int a[] = {0, 0, 1, 0, 0, 0, 1, 2};
    int a[] = {1, 1, 1, 1, 0, 0, 2, 1, 2, 1, 0, 0, 0, 0, 1, 0, 0, 1, 2, 0, 0, 0, 2, 1, 0, 1};
    int n = sizeof(a)/sizeof(a[0]);

    segragate012(a, n);

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    cin.get();
    return 0;
}
/*
0 0 1 0 0 0 1 2
1 1 1 1 0 0 2 1 2 1 0 0 0 0 1 0 0 1 2 0 0 0 2 1 0 1
*/
