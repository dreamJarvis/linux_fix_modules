#include <bits/stdc++.h> 
using namespace std; 

/*Prototype for utility functions */
void printArray(int arr[], int size); 
void swap(int arr[], int fi, int si, int d); 

// A - arr[0..d-1]
// B - arr[d...n]
// si : starting index
void leftRotate(int arr[], int d, int n) { 
	if(d == 0 || d == n)
        return ;

    if(n-d == d){
        swap(arr, 0, n-d, d);
        return ;
    }

    if(d < n-d){
        swap(arr, 0, n-d, d);       // arr, si of 1st sub_array, si of 2nd sub-array
        leftRotate(arr, d, n-d);    
    }
    else {
        swap(arr, 0, d, n-d);
        leftRotate(arr + n - d, 2*d - n, d);
    }
} 

/*UTILITY FUNCTIONS*/
/* function to print an array */
void printArray(int arr[], int size) { 
	int i; 
	for(i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

/*This function swaps d elements starting at index fi 
with d elements starting at index si */
void swap(int arr[], int fi, int si, int d) { 
	int i, temp; 
	for(i = 0; i < d; i++) 
        swap(arr[fi+i], arr[si+i]);
} 

// Driver Code 
int main() { 
	int arr[] = {1, 2, 3, 4, 5, 6, 7}; 
	leftRotate(arr, 2, 7); 
	printArray(arr, 7); 
	return 0; 
} 

// This code is contributed by rathbhupendra 
