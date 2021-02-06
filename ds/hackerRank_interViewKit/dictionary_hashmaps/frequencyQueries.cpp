// hackerRank : frequency Queries
#include <bits/stdc++.h>
using namespace std;

/*  we have taken 2 maps,
    first one keeps tracks of each value and its frequency in the array
    second one keeps tracks of the frequency that are currently available i.e
    it will keep track of how many numbers in the array have this current frequency
    so second map maps, frequency --> values
    i.e these values in the array have this frequency
*/
vector<int> freqQuery(vector<vector<int>> queries) {
    int n = queries.size();;

    vector<int> results;
    unordered_map<long, long> valueFreq;
    unordered_map<long, long> freqByValue;

    for(int i = 0 ; i < n; i++){
        long type = queries[i][0];
        long value = queries[i][1];

        switch(type){
            case 1:
                // so whenever a value is added or deleted in the array, it's frequency will change too, .'. the for its current frequency, in the freqByValue we will decrement by 1 in freqByValue for this frequency of this value, which tells us that no values that have this much frequency, now we have one less, or one more of that value in the array
                freqByValue[valueFreq[ value ]]--;
                valueFreq[ value ]++;
                freqByValue[valueFreq[ value ]]++;
                break;
            case 2:
                if(valueFreq[ value ] > 0){
                    freqByValue[valueFreq[ value ]]--;
                    valueFreq[ value ]--;
                    freqByValue[valueFreq[ value ]]++;
                }
                break;
            case 3:
                results.push_back(( freqByValue[value] > 0 )? 1:0);
                break;
            default:
                break;
        }

    }
    return results;
}

// Driver function
int main(){
    vector<vector<int>> arr({
        {1, 1},
        {2, 2},
        {3, 2},
        {1, 1},
        {1, 1},
        {2, 1},
        {3, 2}
    });

    for(auto i:freqQuery(arr))
        cout << i << " ";
    cout << endl;

    return 0;
}
