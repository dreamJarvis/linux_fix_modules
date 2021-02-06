/*
    Design a stack that supports getMin() in O(1) time and O(1) extra space
    https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
*/
#include <bits/stdc++.h>
using namespace std;

class MaxStack {
public:
    vector<int> s;
    int maxElement;

    // constructor
    MaxStack() {}

    void push(int x) {
        if(s.size() == 0){
            maxElement = x;
        }
        else if(x > maxElement){
            int temp = 2*x - maxElement;
            maxElement = x;
            s.push_back(temp);
            return ;
        }
        s.push_back(x);
    }

    void pop() {
        if(s[0] > maxElement){
            maxElement = 2*maxElement - s[0];
        }

        s.erase(s.begin());

        for(auto i:s)
            cout << i << " ";
        cout << endl;
    }

    int getMax() {
        return maxElement;
    }
};

int main(){
    MaxStack m;

    vector<int> arr({9,10,9,-7,-4,-8,2,-6});
    int k = 5;

    int i=0;
    for(; i < k; i++){
        m.push(arr[i]);
    }

    cout << m.getMax() << endl;

    for(int j=k; j < arr.size(); j++){
        // cout << "e : " << arr[j] << endl;
        m.pop();
        m.push(arr[j]);
        cout << m.getMax() << endl;
    }

    return 0;
}
