#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// space : O(1)
stack<int> delMidElement(stack<int> &st, int n){
    // base case
    if(st.size() == (n/2+1)){
        st.pop();
        return st;
    }

    // hypothesis
    int lastNum = st.top();
    st.pop();
    delMidElement(st, n);

    // induction
    st.push(lastNum);
    return st;
}

// Driver function
int main(){
    // vector<int> arr({5, 1, 4, 2, 8});
    vector<int> arr({1, 3});
    // vector<int> arr({-5, -1, -4, -2, -8});
    // vector<int> arr({-5, 10, -12});
    stack<int> st;
    for(auto i:arr)
        st.push(i);

    st = delMidElement(st, st.size());
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
