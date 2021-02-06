// to generate all palindromic substrings in a given string
#include <bits/stdc++.h>
using namespace std;

// check if it is palindrome or not
// tc : O(n)
bool isPalindrome(int arr[], int start, int end){
	while(start <= end){
		if(arr[start] != arr[end])
			return false;
		start++;
		end--;
	}
	return true;
}

// tc : O(n^3)
void generateSubsets(int arr[], int n, int start, int end){
	if(end == n){
		return ;
	}
	else if(start > end){
		generateSubsets(arr, n, 0, end+1);
	}
	else {
		// if palindrome , then print the sub-array
		if(isPalindrome(arr, start, end)){					// O(n)
			cout << "[ ";
			for(int i = start; i < end; i++)
				cout << arr[i] <<", ";
			cout << arr[end] << " ]\n";
		}
		generateSubsets(arr, n, start+1, end);				// O(n^2)
	}
}

// memoisation
// O(n^2)
void generateSubsetsMemo(int arr[], int n, int start, int end, unordered_map<string, bool> &table){
	string key = to_string(start) + "_" + to_string(end);

	if(end == n){
		return ;
	}

	else if(table[key])
		return ;

	else if(start > end){
		generateSubsetsMemo(arr, n, 0, end+1, table);
	}
	else {
		// if palindrome , then print the sub-array
		if(table[key] || isPalindrome(arr, start, end)){					// O(n)
			cout << "[ ";
			for(int i = start; i < end; i++)
				cout << arr[i] <<", ";
			cout << arr[end] << " ]\n";

			table[key] = true;
		}
		generateSubsetsMemo(arr, n, start+1, end, table);				// O(n^2)
	}
}

void generateSubsetsMemoUTIL(int arr[], int n){
	unordered_map<string, bool> table;
	generateSubsetsMemo(arr, n, 0, 0, table);
}


// Tabulation method : O(n^2)
void generateSubsetsDP(int arr[], int n){
	bool dp[n][n] = {false};			// dp table

	// all the single element are palindromes
	for(int i = 0; i < n; i++){
		dp[i][i] = true;
		cout << "[ " << arr[i] << " ]" << endl;
	}

	// finding if there are palindromes of length 2
	for(int i = 0; i < n; i++){
		if(arr[i] == arr[i+1]){
			dp[i][i+1] = true;
			cout << "asd[" << arr[i] << ", "<< arr[i+1] << "]";
		}
	}

	// finding all the palindroes of length >= 3
	for(int len = 3; len <= n; len++){
		for(int row = 0; row < n - len + 1; row++){
			int col = row + len - 1;

			if(arr[row] == arr[col] && dp[row+1][col-1]){
				dp[row][col] = true;

				// printing the possible subset
				cout << "[ ";
				for(int i = row; i <= col; i++)
					cout << arr[i] << ", ";
				cout << " ]"<< endl;
			}
		}
	}

	return ;
}

// Driver function
int main(){
	int arr[] = {1, 2, 3, 2, 1, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	// generateSubsets(arr, n, 0, 0);
	generateSubsetsDP(arr, n);
	// generateSubsetsMemoUTIL(arr, n);


	return 0;
}
