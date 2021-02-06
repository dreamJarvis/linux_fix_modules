// Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].If there is no solution possible, return -1.
#include <bits/stdc++.h>
using namespace std;

// TODO : do it again

// t : O(n^2)
// s : O(1)
int maxDistance(vector<int> &arr){
    int n = arr.size();

    int maxJ = 0;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] <= arr[j])
                maxJ = max((j-i), maxJ);
        }
    }

    return maxJ;
}

// t : O(n)
// s : O(2n)
int maxDistance_2(vector<int> &arr){
    int n = arr.size();

    vector<int> Lmin(n, 0);
    vector<int> Rmax(n, 0);

    int leftMinIndex = 0;
    int leftMinValue = arr[0];

    int rightMaxValue = arr[n-1];
    int rightMaxIndex = n-1;

    for(int i = 0; i < n; i++){
        if(leftMinValue > arr[i]){
            leftMinIndex = i;
            leftMinValue = arr[i];
        }
        Lmin[i] = leftMinValue;
    }

    for(auto value:Lmin)
        cout << value << " ";
    cout << "\n\n";

    for(int i = n-1; i >= 0; i--){
        if(rightMaxValue < arr[i]){
            cout << rightMaxValue << ", " << arr[i] << endl;
            rightMaxIndex = i;
            rightMaxValue = arr[i];
        }
        Rmax[i] = rightMaxValue;
    }

    cout << "max : " << rightMaxValue << ", " << rightMaxIndex << endl;
    cout << "min : " << leftMinValue << ", " << leftMinIndex << "\n\n";

    for(auto value:Rmax)
        cout << value << " ";
    cout << endl;

    int distance_so_far = -1;
    int i = 0, j = 0;

    while(i < n && j < n){
        if(Lmin[i] < Rmax[j]){
            if(j-i > distance_so_far){
                distance_so_far = j-i;
            }
            j++;
        }else   i++;
    }

    return distance_so_far;
}

// t : O(n)
// s : O(n)
int maximumGap(const vector<int> &num) {
    // edge cases:
    if (num.size() == 0) return -1;
    if (num.size() == 1) return 0;

    vector<pair<int, int> > toSort;
    for (int i = 0; i < num.size(); i++) {
        toSort.push_back(make_pair(num[i], i));
    }

    sort(toSort.begin(), toSort.end());

    int len = toSort.size();
    int maxIndex = toSort[len - 1].second;
    int ans = 0;

    for (int i = len - 2; i >= 0; i--) {
        ans = max(ans, maxIndex - toSort[i].second);
        maxIndex = max(maxIndex, toSort[i].second);
    }

    return ans;
}

// Driver function
int main(){
    vector<int> arr({3, 5, 4, 2});

    cout << maxDistance_2(arr) << endl;

    return 0;
}
