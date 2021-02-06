// hackerRank Triple Sum
#include <bits/stdc++.h>
using namespace std;

// O(n)
vector<int> removeDuplicates(vector<int> arr){
    vector<int> A;
    unordered_map<int, bool> temp;
    for(auto i:arr){
        if(!temp.count(i)){
            A.push_back(i);
            temp[i] = true;
        }
    }

    return A;
}

// tc : 2*O(n*log(n))
long triplets(vector<int> A, vector<int> B, vector<int> C) {
    // storing all the unique elements
    A = removeDuplicates(A);
    B = removeDuplicates(B);
    C = removeDuplicates(C);

    int aSize = A.size();
    int bSize = B.size();
    int cSize = C.size();

    // sorting the array's : O(nlog(n))
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    long totalCount = 0;
    // O(nlog(n))
    for(auto i:B){
        int countA = distance(A.begin(), upper_bound(A.begin(), A.end(), i));
        int countB = distance(C.begin(), upper_bound(C.begin(), C.end(), i));

        // cout << i.first << " --  " << countA << " *  " << countB << endl;

        totalCount += (countA * countB);
    }

    return totalCount;
}

// Driver function
int main(){
    // vector<int> a({1, 3, 5});
    // vector<int> b({2, 3});
    // vector<int> c({1, 2, 3});

    // vector<int> a({1, 4, 5});
    // vector<int> b({2, 3, 3});
    // vector<int> c({1, 2, 3});

    vector<int> a({1, 3, 5, 7});
    vector<int> b({5, 7, 9});
    vector<int> c({7, 9, 11, 13});

    cout << triplets(a, b, c) << endl;

    return 0;
}
/*
1 4 5
2 3 3
1 2 3
*/
