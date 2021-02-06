#include <bits/stdc++.h>
using namespace std;

/*
    numbers which 2 can divide : (2, 4, 6, 8, 10.....)
    numbers which 3 can divide : (3, 6, 9.....)
    numbers which 5 can divide : (5, 10....)
    numbers which 7 can divide : (1, 7....)

    as we can see, we check that if the total frequecies of any element
    can be divided by any of these elements, then it can form groups

    ex : {0,0,0,1,1,1,1,1,1,2,2,2,3,3,3,3,3,3,3,3,3}
    here
    freq
        1 : 6
        0 : 3
        2 : 3
        3 : 9

        now, we can see that all of these frequecies are divisible by 3,
        i.e. every number can be divided in to pairs of 3
*/
// O(n)
bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> freq;

    if(deck.size() < 2) return false;

    for(auto &i:deck){
        freq[i]++;
    }

    int minFreq = INT_MAX;
    for(auto &i:freq)
        minFreq = min(minFreq, i.second);

    if(minFreq < 2) return false;

    for(auto &i:freq)
        cout << i.first << " -- " << i.second << endl;

    bool res = false;
    for(int i = 2; i <= 9; i++){
        bool flag = true;
        for(auto &f:freq)
            if(f.second%i){
                flag = false;
                break;
            }

        if(flag)
            res |= true;
    }

    return res;
}

// Driver function
int main(){
    // vector<int> a({1,1,1,2,2,2,3,3});
    // vector<int> a({0,0,0,1,1,1,2,2,2});
    // vector<int> a({1,1,1,1,2,2,2,2,2,2});
    // vector<int> a({0,0,0,0,0,1,1,2,3,4});
    vector<int> a({0,0,0,1,1,1,1,1,1,2,2,2,3,3,3});
    // vector<int> a({1,1,1,1,1,0,0,0});


    cout << hasGroupsSizeX(a) << endl;

    return 0;
}

/*
[0,0,0,1,1,1,2,2,2]
[1,1,1,1,2,2,2,2,2,2]
[0,0,0,0,0,1,1,2,3,4]
[0,0,0,1,1,1,1,1,1,2,2,2,3,3,3]
[1,1,1,1,1,0,0,0]
[1,1,1,1,2,2,2,2,2,2]
*/
