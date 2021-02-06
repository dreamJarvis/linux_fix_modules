// leetcode 155. Min Stack
#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> minStack;

    // constructor
    MinStack() {}

    void push(int x) {
        if(minStack.empty()){
            minStack.push(x);
        }
        else if(x <= minStack.top()){
            minStack.push(x);
        }

        s.push(x);
    }

    void pop() {
        if(s.top() == minStack.top()){
            minStack.pop();
        }

        s.pop();
    }

    int top() {
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
