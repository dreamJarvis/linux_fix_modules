// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

int cntSubSeq(vector<int> &arr, int n){
	int pos_count = 0;
	int neg_count = 0;
	int count;
    int mod = 1000000007;

	for (int i = 0; i < n; i++) {
		if (arr[i] > 0)   pos_count++;
		if (arr[i] < 0)   neg_count++;
	}

	count = ((int)pow(2, pos_count))%mod;

	if (neg_count > 0) count = count%mod * ((int)pow(2, neg_count - 1))%mod;
	else               count = 0;

	return count%mod;
}

// Driver code
int main(){
    int n;
    int size;

    vector<int> arr;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> size;

        int temp = 0;
        for(int j = 0; j < size; j++){
            cin >> temp;
            arr.push_back(temp);
        }

        cout << cntSubSeq(arr, arr.size()) << endl;
    }

	return 0;
}
