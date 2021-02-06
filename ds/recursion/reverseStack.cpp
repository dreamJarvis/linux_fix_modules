// reverse a stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void putInLast(stack<int> &st, int num){
    // base condition
    // put the element at the last
    if(st.empty()){
        st.push(num);
        return;
    }

    // hypothesis
    int val = st.top();
    st.pop();
    putInLast(st, num);

    // induction
    st.push(val);
}

void reverStack(stack<int> &st){
    // base condition
    if(st.size() == 1){
        return;
    }

    // hypothesis
    int lastNum = st.top();
    st.pop();
    reverStack(st);

    // induction
    putInLast(st, lastNum);
}

// Driver function
int main(){
    vector<int> arr({5, 1, 4, 2, 8});
    // vector<int> arr({1});
    // vector<int> arr({-5, -1, -4, -2, -8});
    // vector<int> arr({-5, 10, -12});
    stack<int> st;
    for(auto i:arr)
        st.push(i);

    reverStack(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
