#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> result;
    vector<int> unique;

    unique.push_back(numbers[0]);
    for(int i = 1; i < numbers.size(); i++){
        if(unique.back() != numbers[i]){
            unique.push_back(numbers[i]);
        }
    }

    for(int i = 1; i <= unique.size(); i++){
        for(int j = i+1; j < unique.size(); j++){
            if(unique[i-1] + unique[j-1] == target){
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
    }

    return result;
}

// driver function
int main(){
    vector<int> arr ({2, 2, 2, 7, 7, 11, 15, 15, 15});
    vector<int> result = twoSum(arr, 9);

    cout << result[0] << " " << result[1] << endl;
    return 0;
}
