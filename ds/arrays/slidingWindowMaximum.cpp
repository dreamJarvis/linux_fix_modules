#include <bits/stdc++.h>
using namespace std;

// 212ms
// time complexity : O(n)
// space complexity: O(k)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;
    multiset<int, greater<int>> maxNum;
    int i = 0;
    for(; i < k; i++)   maxNum.insert(nums[i]);
    result.push_back(*maxNum.begin());

    for(; i < n; i++){
        maxNum.erase(maxNum.find(nums[i - k]));
        maxNum.insert(nums[i]);
        result.push_back(*maxNum.begin());
    }

    return result;
}

// A Dequeue (Double ended queue) based method for printing maximum element of
// all subarrays of size k
void printKMax(int arr[], int n, int k){
	// Create a Double Ended Queue, Qi that will store indexes of array elements
	// The queue will store indexes of useful elements in every window and it will
	// maintain decreasing order of values from front to rear in Qi, i.e.,
	// arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
	deque<int> Qi(k);

	/* Process first k (or first window) elements of array */
	int i;
	for (i = 0; i < k; ++i) {
		// For every element, the previous smaller elements are useless so
		// remove them from Qi
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back(); // Remove from rear

		// Add new element at rear of queue
		Qi.push_back(i);
	}

	// Process rest of the elements, i.e., from arr[k] to arr[n-1]
	for (; i < n; ++i) {
		// The element at the front of the queue is the largest element of
		// previous window, so print it
		cout << arr[Qi.front()] << " ";

		// Remove the elements which are out of this window
		while ((!Qi.empty()) && Qi.front() <= i - k)
			Qi.pop_front(); // Remove from front of queue

		// Remove all elements smaller than the currently
		// being added element (remove useless elements)
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();

		// Add current element at the rear of Qi
		Qi.push_back(i);
	}

	// Print the maximum element of last window
	cout << arr[Qi.front()];
}

// Driver function
int main(){
    vector<int> nums({1,3,-1,-3,5,3,6,7});
    int k = 3;
    // vector<int> nums({1, -1});
    // int k = 1;
    // vector<int> nums({-7,-8,7,5,7,1,6,0});
    // int k = 4;

    for(auto i:maxSlidingWindow(nums, k))
        cout << i << endl;
    cout << endl;

    return 0;
}
/*
[-7,-8,7,5,7,1,6,0]
4
*/
