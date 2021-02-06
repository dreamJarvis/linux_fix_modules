// 718. Maximum Length of Repeated Subarray
#include <bits/stdc++.h>
using namespace std;

int findLength(vector<int>& A, vector<int>& B) {
    int aLen = A.size();
    int bLen = B.size();

    vector<vector<int>> dp(bLen, vector<int>(aLen, 0));

    if(A[0] == B[0])
        dp[0][0] = 1;

    for(int i = 1; i < bLen; i++){
        if(B[0] == A[i]){
            dp[0][i] = 1;
        }
    }

    for(int i = 1; i < aLen; i++){
        if(A[0] == B[i]){
            dp[i][0] = 1;
        }
    }

    int maxLen = 0;
    for(int i = 1; i < bLen; i++){
        int counter = 0;
        for(int j = 1; j < aLen; j++){
            if(A[j] == B[i]){
                dp[i][j] = dp[i-1][j-1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
            else                dp[i][j] = 0;
        }
    }


    // for(int i = 0; i < bLen; i++){
    //     for(int j = 0; j < aLen; j++)
    //         cout << dp[i][j] << "\t";
    //     cout << endl;
    // }

    return maxLen;
}

// TLE
// time complexity : O(n^3)
// int findLength(vector<int>& A, vector<int>& B) {
//     if(A.size() < B.size()){
//         vector<int> temp = A;
//         A = B;
//         B = temp;
//     }
//
//     int aLen = A.size();
//     int bLen = B.size();
//
//     int maxLen = 0;
//     for(int i = 0; i < aLen; i++){
//         for(int j = 0; j < bLen; j++){
//             if(A[i] == B[j]){
//                 int ptr_1 = i, ptr_2 = j, count=0;
//                 while(ptr_2 < bLen && ptr_1 < aLen && (A[ptr_1] == B[ptr_2])){
//                     // cout << A[ptr_1] << "\t";
//                     ptr_1++;
//                     ptr_2++;
//                     count++;
//                 }
//                 // cout << "\n\n";
//                 maxLen = max(maxLen, count);
//             }
//         }
//     }
//
//     return maxLen;
// }

// Driver function
int main(){
    vector<int> A({1, 2, 3, 2, 1});
    vector<int> B({3, 2, 1, 4, 7});
    // vector<int> A({0, 0, 0, 0, 0});
    // vector<int> B({0, 0, 0, 0, 0});
    // vector<int> A({0, 1, 1, 1, 1});
    // vector<int> B({1, 0, 1, 0, 1});

    cout << findLength(A, B) << endl;

    return 0;
}
