// leetcode : 853
#include <bits/stdc++.h>
using namespace std;

int carFleet(vector<int> &position, vector<int> &speed, int target){
    int n = position.size();

    // first calculate the arrivalTime of every car, w.r.t the distance they are from the target
    // now store arrival time , w.r.t to their respective positions
    vector<pair<int, double>> cars;
    for(int i = 0; i < n; i++){
        double arrivelTime = (target-position[i])/speed[i];
        cars.push_back(make_pair(position[i], arrivelTime));
    }

    // sorts in ascending order....choti se bdi
    // sort the cars w.r.t to their positios from the target, so taret having max distance to cover will at the top
    sort(cars.begin(), cars.end());


    // for(auto value:cars){
    //     cout << value.first << "--" << value.second << endl;
    // }

    // now when we start from bottom, i.e. we start from the car i.e. nearest to the target
    // so, if the car behind the current car arrives earlier then the current car, then they will make a pair, else the current car will cross the target distance alone, i.e. it will make a fleet of single car
    int ans = 0, t = n;
    while(--t > 0){
        cout << t << endl;
        if(cars[t].second < cars[t-1].second){
            ans++;
            // cout << cars[t].second << ", " << cars[t-1].second << "\tans : "<< ans <<endl;
        }
        else    cars[t-1] = cars[t];
    }

    // there can be 2 possible cases :
    // 1) that the loop terminalted while it was merging cars in a car Fleet
    // 2) ot that it started counting the cars in a new Fleet
    // in both the above conditions, ans has to be incremented by 1, to consider either of the cases
    cout << ans<< "\t" << t << endl;
    return ans + (t == 0 ? 1 : 0);
}

// Driver function
int main(){
    vector<int> position({10, 8, 0, 5, 3});
    vector<int> speed({2, 4, 12, 1, 3});
    // vector<int> position({2, 4});
    // vector<int> speed({3, 2});
    int target = 12;

    cout << carFleet(position, speed,target) << endl;

    return 0;
}
