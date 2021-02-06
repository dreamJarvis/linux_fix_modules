// fractional knapsack problem
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    Item(int value, int weight) : value(value), weight(weight) {}
};

// comparison function to sort item according to value / weight ratio
bool cmp(Item a, Item b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;

    return r1 > r2;
}

// grredy function to solve the knapsack
double fractionalKnapsack(int W, Item arr[], int n){
    sort(arr,  arr+n, cmp);

    int currWeight = 0;         //  current weight in knapsack
    double finalValue = 0.0;    //  result (value in knapsack)

    for(int i = 0; i < n; i++){
        // if adding the whole item won't overflow, add it completely
        if(currWeight + arr[i].weight <= W){
            currWeight += arr[i].weight;
            finalValue += arr[i].value;
        }

        // if we can't add current item, add fractional part of it
        else {
            int remain = W - currWeight;
            finalValue += arr[i].value * ((double)remain/arr[i].weight);    // adding the fractional value
            break;
        }
    }

    return finalValue;
}

// Driver function
int main(){
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Maximum value we can obtai : " << fractionalKnapsack(W, arr, n) << endl;

    return 0;
}
