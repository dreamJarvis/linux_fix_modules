#include <bits/stdc++.h>
using namespace std;

void allPossibleSubset(int arr[],int n){
	int  count = pow(2,n);

	// The outer for loop will run 2^n times to print all subset.
	// Here variable i will act as a binary counter
	for (int i = 0; i < count; i++){
		// The inner for loop will run n times , As the maximum number of elements a set can have is n
		// This loop will generate a subset
        // cout << i << "\t : ";
		for (int j = 0; j < n; j++){
			// This if condition will check if jth bit in binary representation of  i  is set or not
			// if the value of (i & (1 << j)) is greater than 0 , include arr[j] in the current subset
			// otherwise exclude arr[j]
			if ((i & (1 << j)) > 0){
                // cout << "bit : " << (i & (1 << j)) << " ";
				cout << arr[j];
            }
            // cout << (i & (1 << j)) << " ";
		}

		cout << endl;

        // cout << "\t :";
        // for(int j=0; j<n; j++)
        //     if ((i & (1 << j)) > 0){
        //         // cout << "bit : " << (i & (1 << j)) << " ";
		// 		cout << arr[j] << " ";
        //     }

		// cout << endl;
	}
}

int main(){
	int arr[] = {1, 2};
	int n = sizeof(arr)/sizeof(arr[0]);

	allPossibleSubset(arr,n);

	return 0;
}
