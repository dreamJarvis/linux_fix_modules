#include <iostream>
#include <vector>
using namespace std;

// ================================= Method 1 ================================= //
// using BIH
// tc : O(n^2)
void arraySort(vector<int> &arr, int n, int i){
    // base condition
    if(i == n-1){
        return ;
    }

    // hypothesis
    arraySort(arr, n, i+=1);                // O(n)

    // induction
    if(arr[i-1] > arr[i])
        swap(arr[i], arr[i-1]);

    // hypothesis
    arraySort(arr, n, i);                   // O(n)
}

// =================================== Method 2 ================================ //
vector<int> insert(vector<int> nums, int key){
    // base case
    if(nums.size() == 0 || nums[nums.size()-1] <= key){
        nums.push_back(key);
        return nums;
    }

    // hypothesis
    int val = nums[nums.size()-1];
    nums.pop_back();
    nums = insert(nums, key);

    // induction
    nums.push_back(val);
    return nums;
}

vector<int> sort(vector<int> nums){
    // base case
    if(nums.size() == 1)
        return nums;

    // hypothesis
    int lastNum = nums[nums.size() - 1];
    nums.pop_back();
    nums = sort(nums);

    // induction
    return (nums = insert(nums, lastNum));
}


// Driver function
int main(){
    vector<int> arr({20, 10, 14, 8, 4, 32, 1, 3, -1, 12});
    // vector<int> arr({5, 1, 4, 2, 8});

    // arraySort(arr, arr.size(), 0);
    //
    // for(auto i:arr)
    //     cout << i << " ";
    // cout << endl;

    for(auto i:sort(arr))
        cout << i << " ";
    cout << endl;



    return 0;
}
