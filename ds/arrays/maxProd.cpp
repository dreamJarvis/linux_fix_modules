// InterviewBit
#include <bits/stdc++.h>
using namespace std;

// right greater element
// O(n)
vector<int> leftGreater(vector<int> &arr){
    int n = arr.size();
    stack<int> s;
    s.push(0);

    vector<int> result(n, 0);
    for(int i = 1; i < n; i++){
        if(s.empty())
            s.push(i);

        while(!s.empty() && arr[s.top()] < arr[i]){
            result[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return result;
}

// left greater eleent
// O(n)
vector<int> rightGreater(vector<int> &arr){
    int n = arr.size();
    stack<int> s;
    s.push(n-1);

    vector<int> result(n, 0);
    for(int i = n-2; i >= 0; i--){
        if(s.empty())
            s.push(i);
        while(!s.empty() && arr[i] > arr[s.top()]){
            result[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return result;
}

// --- O(n)
int maxProd(vector<int> &arr){
    int n = arr.size();
    if(n==0) return 0;

    vector<int> lGreater = leftGreater(arr);
    vector<int> rGreater = rightGreater(arr);

    int maxProd = INT_MIN;
    for(int i = 0; i < n; i++)
        maxProd = max(maxProd, lGreater[i]*rGreater[i]);
    return maxProd;
}

// ---------------------------------------------------------------------------------//
// O(n)
int maxProd_2(vector<int> &arr){
    int n = arr.size();
    vector<int> LeftSpecialValue(n,0),RightSpecialValue(n,0);

    // left greater values
    stack<int> leftCalc;
	leftCalc.push(0);
	LeftSpecialValue[0]=0;

	for(int i=1;i<n;i++){
		while(!leftCalc.empty()){
			if(arr[leftCalc.top()]>arr[i]) break;
			leftCalc.pop();
		}
		LeftSpecialValue[i] = (leftCalc.empty())?0:leftCalc.top();
		leftCalc.push(i);
	}

    // right greater values
    stack<int> rightCalc;
	rightCalc.push(n-1);
	RightSpecialValue[n-1]=0;

	for(int i=n-2;i>=0;i--){
		while(!rightCalc.empty()){
			if(arr[rightCalc.top()]>arr[i]) break;
			rightCalc.pop();
		}
		RightSpecialValue[i] = (rightCalc.empty())?0:rightCalc.top();
		rightCalc.push(i);
	}

    long long mx = INT_MIN;
	for(int i=0;i<n;i++){
		mx=max(mx,LeftSpecialValue[i]*1LL*RightSpecialValue[i]);
	}

	return mx%1000000007;
}

// ----------------------------------- Driver function ------------------------------------- //
int main(){
    vector<int> arr({7, 5, 7, 9, 8, 7 });
    // vector<int> arr({5, 9, 6, 8, 6, 4, 6, 9, 5, 4, 9});
    //
    // right Greater elements in the array
    cout << "Right greater :\t";
    for(auto value:leftGreater(arr))
        cout << value << " ";
    cout << endl;

    // left greater elements in the array
    cout << "Left greater :\t";
    for(auto value:rightGreater(arr))
        cout << value << " ";
    cout << endl;

    // max product
    cout << maxProd(arr) << endl;

    return 0;
}
