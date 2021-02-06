#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int findPivot(vector<int> &arr){
	int n = arr.size()-1;
	int s = 0, e = n;

	while(s <= e){
		int mid = (s+e)/2;

		if(arr[mid] > arr[mid+1]){
			return mid;
		}

		if(arr[mid] <= arr[0]){
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}

	return -1;
}

int binarySearch(vector<int> &arr, int s, int e, int K){
	while(s <= e){
		int mid = (s+e)/2;

		if(arr[mid] == K)
			return mid;

		if(arr[mid] < K)
			s = mid+1;
		else
			e = mid-1;
	}

	return -1;
}

int Search(vector<int> arr, int K) {
	int n = arr.size();
	int pivot = findPivot(arr);

	// it means no pivot, the array is sorted.
	if(pivot == -1){
		return binarySearch(arr, 0, n-1, K);
	}

	if(arr[pivot] == K)
		return pivot;
	if(K < arr[0])
		return binarySearch(arr, pivot+1, n-1, K);
	return binarySearch(arr, 0, pivot, K);
}

// Driver function
int main() {
	vector<int> a({5, 6,7,8,9,10,1,2,3});
	long long x = 10;

	// vector<int> a({3,1,2});
	// long long x = 1;

	cout << Search(a, x) << endl;

	cin.get();
	return 0;
}
