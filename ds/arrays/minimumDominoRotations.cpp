// leetcode 1007. Minimum Domino Rotations For Equal Row
#include <bits/stdc++.h>
using namespace std;

// t : O(n)
// s : 4*O(n)
int minDominoRotations(vector<int>& A, vector<int>& B){
    int n = A.size();
    unordered_map<int, int> freqA, freqB;

    // counting freq in A
    for(auto value:A){
        if(freqA.count(value)){
            freqA[value]++;
        }else{
            freqA[value] = 1;
        }
    }

    // counting freq in B
    for(auto value:B){
        if(freqB.count(value)){
            freqB[value]++;
        }else{
            freqB[value] = 1;
        }
    }

    // finding the element with max freq. in A
    int maxFreq = INT_MIN, freqValueA = INT_MIN;
    for(auto value:freqA){
        if(maxFreq < value.second){
            maxFreq = value.second;
            freqValueA = value.first;
        }
    }

    // finding the element with max freq. in B
    maxFreq = INT_MIN;
    int freqValueB = INT_MIN;
    for(auto value:freqB){
        if(maxFreq < value.second){
            maxFreq = value.second;
            freqValueB = value.first;
        }
    }

    int restFreqLengthA = n - freqA[freqValueA];
    int restFreqLengthB = n - freqB[freqValueB];

    int noOfRotationsA = 0, noOfRotationsB = 0;
    vector<int> tempA(n), tempB(n);
    tempA = A;
    tempB = B;

    if(freqB[freqValueA] >= restFreqLengthA){
        for(int i = 0; i < n; i++){
            if(A[i] != freqValueA){
                swap(tempA[i], tempB[i]);
                noOfRotationsA++;
            }
        }
    }

    if(freqA[freqValueB] >= restFreqLengthB){
        for(int i = 0; i < n; i++){
            if(B[i] != freqValueB){
                swap(B[i], A[i]);
                noOfRotationsB++;
            }
        }
    }

    // check to see if really any one of them is sorted or not
    bool flagA = true, flagB = true;
    for(int i = 1; i < n; i++){
        if(tempA[i-1] != tempA[i]){
            flagA = false;
        }

        if(B[i-1] != B[i]){
            flagB = false;
        }
    }


    if(flagA && flagB)  return min(noOfRotationsA, noOfRotationsB);
    else if(flagA)      return noOfRotationsA;
    else if(flagB)      return noOfRotationsB;

    return -1;
}

// solution 2
// min no. of rotations required inorder to make any one of the array have same values
int minDominoRotations2(vector<int> &A, vector<int> &B){
    if(A.empty() || B.empty())  return -1;

    int res = A.size() + 1;         //  max. no. of rotations + 1

    // so no it is given that a domino can have values from 1 -> 6
    // so the repetions in any one of the array will have repetions of any number from 1->6
    // so we will check how many repetions the array has to do for each number from 1 -> 6, inorder to have each index of that number
    // mtlb hme kitne swap krne pdenge taki hme uss array ke hr index pr num number mil jaye(num => (1, 6))
    for(int i = 1; i <= 6; i++){
        int first = 0, second = 0, k = 0;

        while(k < A.size() && (A[k] == i || B[k] == i)){
            if(A[k] != i)   first++;
            if(B[k] != i)   second++;
            k++;
        }

        if(k == A.size()){
            res = min(res, min(first, second));
        }
    }

    if(res == A.size() + 1) return -1;
    return res;
}

// solution 3
int minDominoRotations3(vector<int> &A, vector<int> &B){
    if(A.empty() || B.empty()){
        return -1;
    }

    // size
    int n = A.size();

    // 4 possibilities
    vector<int> poss({A[0], A[1], B[0], B[1]});

    // for A
    int minRotationsA = n+1;
    for(int i = 0; i < 4; i++){
        int rotations = 0;
        for(int j = 0; j < n; j++){
            if(A[j] != poss[i]){
                if(B[j] == poss[i])
                    rotations++;
                else{
                    rotations = n+1;
                    break;
                }
            }
        }

        minRotationsA = min(minRotationsA, rotations);
    }

    // For B
    int minRotationsB = n+1;
    for(int i = 0; i < 4; i++){
        int rotations = 0;
        for(int j = 0; j < n; j++){
            if(B[j] != poss[i]){
                if(A[j] == poss[i])
                    rotations++;
                else{
                    rotations = n+1;
                    break;
                }
            }
        }

        minRotationsB = min(minRotationsB, rotations);
    }

    int minRotations = min(minRotationsA, minRotationsB);

    if(minRotations == n+1) return -1;
    return minRotations;
}


// Driver function
int main(){
    vector<int> A({2,1,2,4,2,2});
    vector<int> B({5,2,6,2,3,2});

    // cout << minDominoRotations(A, B) << endl;
    cout << minDominoRotations3(A, B) << endl;

    return 0;
}
