// Recipe for philosopher stone
#include <bits/stdc++.h>
using namespace std;

vector<int> rectColor(vector<vector<int>> &rectangle, int N){
    // stores the area coverd by each area
    vector<int> color(N, 0);

    // int l_Origin = rectangle[N-1][0]/2, b_Origin = rectangle[N-1][1]/2;
    int area = rectangle[N-1][0] * rectangle[N-1][1];   
    color[rectangle[N-1][2]] = area;

    int prev_l = rectangle[N-1][0]/2, prev_b = rectangle[N-1][1]/2;
    for(int i = N-2; i >= 0; i--){
        int l_diff = rectangle[i][0]/2 - prev_l;
        int b_diff = rectangle[i][1]/2 - prev_b;

        cout << "l : " << prev_l << ", b : " << prev_b ;

        prev_l = max(rectangle[i][0]/2, prev_l);
        prev_b = max(rectangle[i][1]/2, prev_b);

        int total_area = 0;
        if(l_diff > 0){
            total_area += 2*(l_diff * rectangle[i][1]);

            if(b_diff > 0)
                total_area += 2*(b_diff * rectangle[i+1][0]);
        }
        else if(b_diff > 0 and l_diff < 0)
            total_area += 2*(b_diff * rectangle[i][0]);

        cout << ",  area: " << total_area << endl;
        color[rectangle[i][2]] += total_area;
    }

    return color;
}

// Driver function
int main(){
    int testCases, N, C;
    cin >> testCases;

    vector<vector<int>> rectangles;

    int val;
    for(int i = 0; i < testCases; i++){
        cin >> N >> C;
        for(int j = 0; j < N; j++){
            int l, b, color;
            cin >> l >> b >> color;
            rectangles.push_back({l, b, color});
        }

        vector<int> result = rectColor(rectangles, N);
        for(int i = 1; i < N; i++)
            cout << result[i] << " ";
        cout << endl;
    }

    return 0;
}

/*
1
5 4
2 2 1
2 8 3
10 2 1
8 4 2
4 6 4
*/