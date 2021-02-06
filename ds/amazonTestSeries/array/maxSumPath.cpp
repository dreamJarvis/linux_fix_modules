#include <bits/stdc++.h>
using namespace std;

int max_path_sum(int A[], int B[], int l1, int l2){
    int i = 0, j = 0;
    int sum1 =0, sum2 =0, sum =0;

    while( i < l1 && j < l2){
        if( i < l1 && A[i] < B[j]){
              sum1 += A[i];
              i++;
        }

        if(j < l2 && B[j] < A[i]){
            sum2 += B[j];
            j++;
        }

        if(A[i] == B[j]){
          sum1 += A[i++];
          sum2 += B[j++];

          if( sum1 == sum2) sum+= sum1;
          else sum += max(sum1, sum2);


          sum1 = 0;
          sum2 =0;
        }
    }

    while( i < l1){
      sum1 += A[i++];
    }

    while( j < l2){
      sum2 += B[j++];
    }

    sum += max(sum1, sum2);
    return sum;
}

int main(){
    int A[] = {2,3,7,10,12};
    int l1 = sizeof(A)/sizeof(A[0]);

    int B[] = {1,5,7,8};
    int l2 = sizeof(B)/sizeof(B[0]);

    // int A[] = {1, 2, 4};
    // int l1 = sizeof(A)/sizeof(A[0]);
    //
    // int B[] = {1, 2, 7};
    // int l2 = sizeof(B)/sizeof(B[0]);

    cout << max_path_sum(A, B, l1, l2);

    return 0;
}
