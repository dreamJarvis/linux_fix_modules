#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n = 0;
    cin >> n;

    vector<ll> required;
    vector<ll> available;

    ll temp = 0, j = 0;
    for(j = 0; j < n; j++){
        cin >> temp;
        required.push_back(temp);
    }

    for(j = 0; j < n; j++){
        cin >> temp;
        available.push_back(temp);
    }

    ll maxNumber = INT_MAX;
    for(j = 0; j < n; j++){
        maxNumber = min(maxNumber, available[j]/required[j]);
    }

    cout << maxNumber << endl;

    return 0;
}
