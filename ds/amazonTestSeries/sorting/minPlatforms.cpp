#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// // why not working ? same approah as below ??
// int findPlatform(int arr[], int dep[], int n){
//     set<pair<int, int>> st;
//     for(int i = 0; i < n; i++){
//         st.insert({arr[i], dep[i]});
//     }
//
//     int totalPlatforms(0);
//     auto it = st.begin();
//
//     int currArr(0), currDept(0);
//     int prevArr = it->first;
//     int prevDept = it->second;
//     it++;
//
//     for(; it != st.end(); it++){
//         currArr = it->first;
//         currDept = it->second;
//
//         if(currArr < prevDept || prevArr == currArr){
//             totalPlatforms++;
//         }
//
//         prevDept = max(currDept, prevDept);
//         currArr = min(currArr, prevArr);
//     }
//
//     return totalPlatforms > 0 ? totalPlatforms:1;
// }

int findPlatform(int arr[], int dep[], int n){
    sort(arr, arr+n);
    sort(dep, dep+n)

    int platformsNeeded = 1, result = 1;
    int i = 1, j = 0;

    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            platformsNeeded++;
            i++;
        }
        else if(arr[i] > arr[j]){
            platformsNeeded--;
            j++;
        }

        result = max(result, platformsNeeded);
    }

    return result;
}

// Driver function
int main(){
    FIO;

    int arr[] = {900,  940, 950,  1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};

    // int arr[] = {900, 1100, 1235};
    // int dep[] = {1000, 1200, 1240};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << findPlatform(arr, dep, n) << endl;

    cin.get();
    return 0;
}
