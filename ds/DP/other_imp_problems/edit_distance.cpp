// leetcode 72: Edit distance
// youtube link : https://www.youtube.com/watch?v=MiqoA-yF-0M
#include <bits/stdc++.h>
using namespace std;

// n -> length of string 1
// m -> length of string 2
// time complexity : O(n*m)
// space complexity : O(n*m)
int minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();

    vector<vector<int>> matrix(len1+1, vector<int>(len2+1, -1));

    // initializing values
    // when the word we have "" into a word.
    // the only thing we can do to make an empty string into an word is insert all those Characters, i.e. insertion
    for(int i = 0; i < len1+1; i++)
        matrix[i][0] = i;

    // the only thing we can do to convert an word to an empty string is deletion
    for(int i = 0; i < len2+1; i++)
        matrix[0][i] = i;

    // filling values according to the minimum cost requeired
    for(int i = 1; i < len1+1; i++){
        for(int j = 1; j < len2+1; j++){
            if(word1[i-1] == word2[j-1]){
                matrix[i][j] = matrix[i-1][j-1];
            }
            else
                matrix[i][j] = min( matrix[i-1][j],
                                    min(matrix[i][j-1], matrix[i-1][j-1])
                               ) + 1;
        }
    }

    return matrix[len1][len2];
}

// Driver function
int main(){
    // string word1 = "horse";
    // string word2 = "ros";
    string word1 = "intention";
    string word2 = "execution";

    cout << minDistance(word1, word2) << endl;

    return 0;
}
