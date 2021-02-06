// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

int binaryMedian(vector<vector<int>> &arr){
	int row = arr.size();
	int col = arr[0].size();
	int smallest = INT_MAX, largest = INT_MIN;

	for(int i = 0; i < row; i++){
		// Finding minimum element
		smallest = min(smallest, arr[i][0]);
		largest = max(largest, arr[i][col-1]);		// Finding minimum element
	}

	int desired = (row*col + 1)/2;

	while(smallest < largest){
		int mid = smallest + (largest - smallest)/2;
		int place = 0;

		// find out no. of elemtns smaller than mid in every row
		for(int i = 0; i < row; ++i)
			place += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();

		if(place < desired)
			smallest = mid + 1;
		else
			largest = mid;
	}

	return smallest;
}

// Driver code
int main(){
	vector<vector<int>> arr{{1, 3, 3},
							{2, 6, 9},
							{3, 6, 9}
						};
	cout << binaryMedian(arr) << endl;
	return 0;
}
