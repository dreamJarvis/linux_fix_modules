// sort a stack recursively
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

// ========================== Method 1 ============================= //
// BIH/
void sortStack(stack<int> &st){
    // base case
    if(st.size() == 1)
        return ;

    // hypothesis
    int lastNum = st.top();
    st.pop();
    sortStack(st);

    // induction
    if(lastNum > st.top()){
        int temp = st.top();
        st.pop();
        st.push(lastNum);
        st.push(temp);

        // hypothesis
        sortStack(st);
    }
    else
        st.push(lastNum);       // induction
}

// ================================ Method 2 =================================//
// BIH
stack<int> insert(stack<int> st, int key){
    // base case
    if(st.size() == 0 || st.top() >= key){
        st.push(key);
        return st;
    }

    // hypothesis
    int val = st.top();
    st.pop();
    st = insert(st, key);

    // induction
    st.push(val);
    return st;
}

stack<int> stackSort(stack<int> st){
    // base case
    if(st.size()==1)
        return st;

    // hypothesis
    int lastNum = st.top();
    st.pop();
    st = stackSort(st);

    // induction
    return (st = insert(st, lastNum));
}


// Dirver function
int main(){
    vector<int> arr({20, 10, 14, 8, 4, 32, 1, 3, -1, 12});
    // vector<int> arr({5, 1, 4, 2, 8});
    // vector<int> arr({-5, -1, -4, -2, -8});
    // vector<int> arr({-5, -10});
    stack<int> st;
    for(auto i:arr)
        st.push(i);

    // sortStack(st);
    st = stackSort(st);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
