#include <bits/stdc++.h>
using namespace std;

/*
* Your MinStack object will be instantiated and called as such:
    * MinStack* obj = new MinStack();
    * obj->push(x);
    * obj->pop();
    * int param_3 = obj->top();
    * int param_4 = obj->getMin();
*/
class MinStack {
public:
    vector<pair<int, int>> st;

    // here, every element contains with it, an minimum element in the stack
    void push(int x){
        if(st.empty() || x <= st[st.size()-1].second)   st.push_back(make_pair(x, x));
        else    st.push_back(make_pair(x, st[st.size()-1].second));
    }

    void pop(){
        return st.pop_back();
    }

    int top(){
        return st[st.size()-1].first;
    }

    int getMin(){
        return st[st.size()-1].second;
    }
};

// Driver function
int main(){
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();
    minStack.pop();
    minStack.top();
    minStack.getMin();

    return 0;
}
