/*
    Design a stack that supports getMin() in O(1) time and O(1) extra space
    https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
*/
#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> s;
    int minElement;

    // constructor
    MinStack() {}

    void push(int x) {
        if(s.empty()){
            minElement = x;
        }
        else if(x < minElement){
            int temp = 2*x - minElement;
            minElement = x;
            s.push(temp);
            return ;
        }
        s.push(x);
    }

    void pop() {
        if(s.top() < minElement){
            minElement = 2*minElement - s.top();
        }

        s.pop();
    }

    int top() {
        if(s.top() < minElement){
            return minElement;
        }
        return s.top();
    }

    // tc : O(1)
    // sc : O(n)
    int getMin() {
        return minStack.top();
    }
};

int main(){
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.getMin() << endl;

    return 0;
}
