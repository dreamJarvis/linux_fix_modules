#include <bits/stdc++.h>
using namespace std;

// // alice ranks
// // t : O(n^2)
// // s : O(1)
// vector<int> aliceRank(vector<int> &alice, vector<int> &scores){
//     int scoreSize = scores.size();
//     int aliceSize = alice.size();
//
//     for(int i = 0; i < aliceSize; i++){
//         int index = 1;
//         for(int j = 0; j < scoreSize; j++){
//             if(j == 0){
//                 if(alice[i] < scores[j])    index++;
//                 else    break;
//             }
//             else if(alice[i] < scores[j]  && scores[j] != scores[j-1] ){
//                 index++;
//             }
//         }
//
//         alice[i] = index;
//     }
//
//     return alice;
// }

// t : O(n)
// s : O(n)
vector<int> aliceRank(vector<int> &alice, vector<int> &scores){
    int scoreSize = scores.size();
    int aliceSize = alice.size();

    vector<int> realScores;
    for(int i = 0; i < scoreSize; i++){
        if(i == 0){
            realScores.push_back(scores[i]);
        }
        else if(realScores[realScores.size()-1] != scores[i]){
            realScores.push_back(scores[i]);
        }
    }

    // cout << realScores.size() << "\n\n";
    // for(auto val:realScores)
    //     cout << val << " ";
    // cout << endl;

    int ptrScores = realScores.size() - 1;
    // cout << "size" << ptrScores << endl;
    int ptrAlice = 0;

    while(ptrAlice < aliceSize && ptrScores >= 0){
        if(alice[ptrAlice] > realScores[ptrScores]){
            // cout << alice[ptrAlice] << " >  " << realScores[ptrScores] << endl;
            ptrScores--;
        }
        else if(alice[ptrAlice] < realScores[ptrScores]){
            // result.push_back(ptrScores+1);
            alice[ptrAlice] = ptrScores+2;
            // cout << alice[ptrAlice] << " < " << ptrScores+1 << endl;
            ptrAlice++;
        }
        else if(alice[ptrAlice] == realScores[ptrScores]){
            // result.push_back(ptrScores);
            alice[ptrAlice] = ptrScores+1;
            // cout << alice[ptrAlice] << " = " << ptrScores << endl;

            ptrAlice++;
            ptrScores--;
        }
    }

    if(ptrScores < 0){
        ptrScores = 1;
    }

    while(ptrAlice < aliceSize){
        alice[ptrAlice++] = ptrScores;
    }

    // for(auto values:alice)
    //     cout << values << " ";
    // cout << endl;

    return alice;
}

// Driver function
int main(){
    // input : 1
    vector<int> alice({5, 25, 50, 120});
    vector<int> scores({100, 100, 50, 40, 40, 20, 10});

    // // input : 2
    // vector<int> alice({50, 65, 77, 90, 102});
    // vector<int> scores({100, 90, 90, 80, 75, 60});

    for(auto value:aliceRank(alice, scores))
        cout << value << " ";
    cout << endl;

    return 0;
}
