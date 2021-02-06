/*
    gfg ATS 9. Sorted subsequence of size 3
    https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/0/?track=amazon-arrays&batchId=192#

    leetcode 334. Increasing Triplet Subsequence
    https://leetcode.com/problems/increasing-triplet-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

// tc : O(N)
// sc : 4*O(N)
vector<int> find3NumbersIII(vector<int> arr, int n) {
    vector<int> ngr(n, INT_MIN);     // next greatest right
    vector<int> nsl(n, INT_MAX);     //  next smallest left

    stack<int> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && arr[i] > arr[s.top()]){
            ngr[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    stack<int> p;
    for(int i = n-1; i >= 0; i--){
        while(!p.empty() && arr[i] < arr[p.top()]){
            nsl[p.top()] = arr[i];
            p.pop();
        }
        p.push(i);
    }

    for(int i = 0; i < n; i++){
        if(nsl[i] < arr[i] && arr[i] < ngr[i])
            return vector<int>({nsl[i], arr[i], ngr[i]});
    }

    return vector<int>({});
}

// tc : O(N)
// sc : O(N)
vector<int> find3NumbersII(vector<int> arr, int N){
    /*
        a.t.q. left < i'th < right i.e. left should contain the smaller elements
        while right contain lerger elements
    */
    // storing all the smllest elements from left side
    vector<int> smaller(N, INT_MAX);
    smaller[0] = arr[0];
    for(int i = 1; i < N; i++){
        smaller[i] = min(arr[i], smaller[i-1]);
    }

    // storing all the greatest elements from the right side
    vector<int> larger(N, INT_MIN);
    larger[N-1] = arr[N-1];
    for(int i = N-2; i >= 0; i--){
        larger[i] = max(arr[i], larger[i+1]);
    }

    for(int i = 1; i < N-1; i++){
        if(arr[i] > smaller[i] && arr[i] < larger[i])
            return vector<int>({smaller[i], arr[i], larger[i]});
    }

    return vector<int>({});
}

// O(N)
// O(1)
vector<int> find3Numbers(vector<int>& nums, int N){
    // If number of elemets < 3
    // then no triplets are possible
    if (nums.size() < 3){
    	return vector<int>({});
    }

    // track best sequence length
    // (not current sequence length)
    int seq = 1;

    // min number in array
    int min_num = nums[0];

    // least max number in best sequence
    // i.e. track arr[j] (e.g. in
    // array {1, 5, 3} our best sequence
    // would be {1, 3} with arr[j] = 3)
    int max_seq = INT_MIN;

    // save arr[i]
    int store_min = min_num;

    // Iterate from 1 to nums.size()
    for (int i = 1; i < nums.size(); i++){
    	if (nums[i] == min_num)
    	continue;

    	else if (nums[i] < min_num)
    	{
    	min_num = nums[i];
    	continue;
    	}

    	// this condition is only hit
    	// when current sequence size is 2
    	else if (nums[i] < max_seq) {

        	// update best sequence max number
        	// to a smaller value
        	// (i.e. we've found a
        	// smaller value for arr[j])
        	max_seq = nums[i];

        	// store best sequence start value
        	// i.e. arr[i]
        	store_min = min_num;
    	}

    	// Increase best sequence length &
    	// save next number in our triplet
    	else if (nums[i] > max_seq){
        	seq++;

        	// We've found our arr[k]!
        	// Print the output
        	if (seq == 3){
        		return vector<int>({store_min, max_seq, nums[i]});
        	}

        	max_seq = nums[i];
    	}
    }

    return vector<int>({});
}

// Driver function
int main(){
    // vector<int> arr({1,2,1,1,3});
    // vector<int> arr({1, 1, 3});
    vector<int> arr({58, 15, 44, 54, 36, 33, 93, 7, 18, 69, 30, 39, 60, 51});
    // vector<int> arr({33, 24, 92, 74, 100, 72, 72, 97, 54, 77, 95, 52, 11, 95, 29});

    // for(auto &i:find3Numbers(arr, arr.size()))
    //     cout << i << " ";
    // cout << endl;

    for(auto &i:find3Numbers(arr, arr.size()))
        cout << i << " ";
    cout << endl;

    return 0;
}
