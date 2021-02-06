// hacker rnak : ice creame parlour
#include <bits/stdc++.h>
using namespace std;

void whatFlavors(vector<int> cost, int money) {
    int n = cost.size();
    multimap<int, int> freq;

    for(int i = 0; i < n; i++){
        freq.insert(make_pair(cost[i], i+1));
    }

    for(auto i:freq){
        int k = money - i.first;
        auto temp = freq.find(k);
        if(freq.count(k) && temp->second != i.second){
            int a = min(i.second, temp->second);
            int b = max(i.second, temp->second);
            cout << a << " " << b << endl;
            return ;
        }
    }
}


// Driver function
int main(){
    vector<int> cost({2, 1, 3, 5, 6});
    int money = 5;
    // vector<int> cost({1, 4, 5, 3, 2});
    // int money = 4;
    // vector<int> cost({2, 2, 4, 3});
    // int money = 4;

    whatFlavors(cost, money);

    return 0;
}
