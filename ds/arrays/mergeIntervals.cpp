#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    static bool compare(const pair<int, int> &p1, const pair<int, int> &p2){
        if(p1.first <= p2.first){
            if(p1.first == p2.first){
                if(p1.second > p2.second)   return true;
            }
            if(p1.first < p2.first) return true;
        }
        return false;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> ranges;
        vector<vector<int>> ans;

        for(auto i:intervals){
            ranges.push_back(make_pair(i[0], i[1]));
        }

        // for(auto i:ranges)
        //     cout << i.first << "-" << i.second << endl;

        // sort(ranges.begin(), ranges.end(), compare);

        int x = ranges[0].first;
        int y = ranges[0].second;
        ans.push_back({x, y});


        for(int i = 1; i < ranges.size(); i++){
            int a = ranges[i].first;
            int b = ranges[i].second;

            //  partial overlap
            if(a < y && b > y){
                ans[ans.size()-1][1] = b;
                y = b;
            }

            // no overlapping
            else if(a > y && b > y){
                ans.push_back({a, b});
                x = a;
                y = b;
            }
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> intervals({
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    });

    Solution s;
    for(auto i:s.merge(intervals))
        cout << "(" << i[0] << ", " << i[1] << "),  ";

    return 0;
}
