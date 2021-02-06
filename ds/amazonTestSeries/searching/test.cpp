#include <bits/stdc++.h>
using namespace std;

#define ll long long int

double MedianOfArrays(vector<int>& arr1, vector<int>& arr2){
	int n = arr1.size();
	int m = arr2.size();

	if(n > m)
		return MedianOfArrays(arr2, arr1);

	int low = 0, high = n;
	while(low <= high){
		int partitionX = (low+high)/2;
		int partitionY = (n+m+1)/2 - partitionX;

		// X :-> left and right side
		int maxLeftX = partitionX == 0 ? INT_MIN : arr1[partitionX-1];	
		int minRightX = partitionX == n ? INT_MAX : arr1[partitionX]; 

		// Y :-> left and right side
		int maxLeftY = partitionY == 0 ? INT_MIN : arr2[partitionY-1];
		int minRightY = partitionY == m ? INT_MAX : arr2[partitionY];

		if(maxLeftX <= minRightY && maxLeftY <= minRightX){
			if((n+m)%2){
				return (double)(max(maxLeftY, maxLeftX));
			}
			else{
				return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
			}
		}
		else if(maxLeftX > minRightY){
			high = partitionX-1;
		}
		else
			low = partitionX+1;
	}


	return -1;	
}

// Driver function
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	vector<int> arr1(n);
	vector<int> arr2(m);
	for(int i = 0; i < n; i++)
		cin >> arr1[i];

	for(int i = 0; i < m; i++)
		cin >> arr2[i];

	cout << MedianOfArrays(arr1, arr2) << endl;

	return 0;
}
/*
Example 1:

Input:
3 4
1 5 9
2 3 6 7
Output: 5

Example 2:

Input:
2 4
4 6
1 2 3 5
Output: 3.5

3 1 5 9
4 2 3 6 7

0
2 1 2
*/
