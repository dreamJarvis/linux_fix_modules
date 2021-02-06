// 659. Split Array into Consecutive Subsequences
/*
    Given an array nums sorted in ascending order, return true if and only if you can split it into 1 or more subsequences such that each subsequence consists of consecutive integers and has length at least 3.
*/
#include <bits/stdc++.h>
using namespace std;

// greedy approach
// time complexity : O(n)
// space complexity : O(n) + O(no. of repeating elements)
bool isPossible(vector<int>& arr) {
    // hm yaha 2 hashmaps lenege,
    // existingSequences : is hashmap me, hr series ke khtm hone ke badh jo number possibly add ho skta h uss series me, hm wo number ko yaha save kr denge
    // createNewSequences : ye given array me hr number ki frequency store krege
    unordered_map<int, int> existingSequences;
    unordered_map<int, int> createNewSequences;     // frequency Counter

    // counting freauency of each number in the array
    for(auto num:arr){
        if(createNewSequences.count(num)){
            createNewSequences[num]++;
        }else{
            createNewSequences[num] = 1;
        }
    }

    // counting all the Consecutive subsequences
    for(auto num:arr){
        if(createNewSequences[num] == 0)    continue;   // if the frequency of number is 0, then skip that number

        // it is a greedy solution, .'. we will check that if the current number can be attached to an existing subsequence, before starting a subsequence from this number,
        // agr ye number kisi subsequence me attach ho skta h, toh pehle issko waha attach kr denge, or subsequently, iss no. ka consecutive number save kr denge existingSequences me, ki agar hme aage koi aesa number milta h, jo iss consecutive no. ke equal h, toh woh hm issme add kre denge
        if(existingSequences.count(num) && existingSequences[num] > 0){
            existingSequences[num] -= 1;                                            // ye number multiple series me included ho skta h, isiliye hr baari kisi series me include hone ke badh, hm isse decrement kr denge

            // jb ye number kisi series me include ho gaya, isska mtlb h ki hme ye number actual array me mil gaya, toh hm isse next consecutive number ko existingSequences me add kr denge, ki jb hme ye number aage milte toh hm usse iss series me include kr ske
            if(existingSequences.count(num+1))  existingSequences[num+1] += 1;
            else                                existingSequences[num+1] = 1;

            // iss number ki actual frequency decerement krna
            createNewSequences[num] -= 1;
        }

        // lekin agr wo number kisi existing freauency me nhi add ho skta, toh hm iss number se ek nyi series start krenge, (and hme question me diya gaya h min length of string 3 honi chahiye)
        else if((createNewSequences.count(num) && createNewSequences.count(num+1) && createNewSequences.count(num+2)) &&
                (createNewSequences[num] > 0 && createNewSequences[num+1] > 0 && createNewSequences[num+2] > 0 )
            ){
                createNewSequences[num] -= 1;
                createNewSequences[num+1] -= 1;
                createNewSequences[num+2] -= 1;

                // aor iss series ke next consequetive number hm, existingSequences me add kr denge, ki jb ye number milega actual series me toh usse iss series me add ske
                if(existingSequences.count(num+3))  existingSequences[num+3] += 1;
                else                                existingSequences[num+3] = 1;
            }
        else
            return false;       // agar aesa ho, ki khi koi sequence na bn paaye, ya koi number aesa h array me ki wo kisi sequence me add nhi ho rha, toh then we will return false
    }

    // else agr sb smmothly jaa raha h toh hm true return kr denge
    return true;
}

// Driver function
int main(){
    // vector<int> arr({1,2,3,3,4,4,5,5});
    vector<int> arr({1,2,3,4,4,5});

    cout << isPossible(arr) << endl;

    return 0;
}
