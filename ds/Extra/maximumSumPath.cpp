// To find the maximum sum path in a given 2d matrix
#include <bits/stdc++.h>
using namespace std;

// recursive approach
/*
     ___________
    | ->| ->| ->|
    |___|___|___|
    |   |   | | |  in this matrix we are allowed to move right :  moving right >> cols + 1, column wise
    |___|___|_V_|                                        down  :  moving down |   row + 1, rowise
    |   |   |   |                                                             V                                                     _   _
    |___|___|___|                                        diagonally : i.e. row + 1, col + 1 (usko represent figure me nhi krna aata  _|_

    Approach DP:
    1)  hr particular row me hme hr column values ko add krne pr(adding upto that point)
        a) iske liye hm , uss row ke hr column pr jana pdega , aor waha tk jana ka total sum nikaalna pdega, (sum of all the previous col), pr hm kisi bhi position pr 3 dir^n se aa skte h , jesa ki question me bata rakha h(dir^ns can vary),
            a) ek side case, ex a -> b jane ke 2 ways h, and c -> d jane ke 4 ways h, d -> b jane ke 2 ways h, phir a -> b jane ke kitne ways h ?
                a -> b = 2, c -> d = 4, toh d -> b jane ke 2 ways h, toh c -> b jane ke 6 ways h, toh total b tk jane ke hmare paas kitne tareeke h ?
                a -> b, c -> b, d -> b, ye hmare paas 3 tareke h b tk pochne ke, yah pr hme kyuki c -> d ka raasta pta tha, toh jb hme c -> b jana that toh hmne bs c -> d, tk aane ka jo sum tha wo + kr diya d -> b me, toh hmare paas c -> b tk jane ka sum aa gaya

            similar approach lgayenge hm iss me

        b) ab hr column, uss row ke, apne se upr wale row ke ussi column, aor apne se upr wale row ka diagonal col, (hme 3 dir^n given h, jesa ki illustration me dikha rkha h), ka max nikalega max(upr wala row with same col, (explained in a bit) upr wale row ka diagonal col) , aor usse apne wale sum ki jo value h usse se add kr lega,
        toh hmare paas ab iss row ke iss column pr, starting point (0,0) se aane tk jo maximum value milgi woh isski value hogi

        c) aor jb aese krte krte jb hm (n-1, m-1) position pr honge toh hme bas yhi dekhna pdega ki iss point se pehle point tk kitna max sum tha, pr hm 3 dir^n se possibly (n-1, n-1) tk aa skte the, toh hme un dir^n pr jo elements lie krte h unka max leke issme add kr denge, (aor wo elements jo 3 dir^n ke h, unke pass apne tk pochne ki max value stored hogi unke 3 dir^n ki max, aor ye silseela aese he chlta rehta h, jb tk hme hamri manzil nhi mil jati, jo he (n-1, m-1))

    2) toh agr hm 1st row pr h toh hme usse upr wali value kese milegi, phir toh error aana chahiye ??
        a) simple, hm pehle 1st row ke column wise iterate kr lete h, aor sum store krate jate h
        b) same krenge 1st column ke liye

    3)ab jb hmare paas 1st row and 1st col ki value h, toh ab hm apni dynamic approach laga skte h.
        a) jo h max( max(upr wala row with same col,  upr wale row ka diagonal col)
*/

// recursive approach me, hm literally hr possible path se jaa rhe h, end point tk, aor unme se jo bhi
void maxSumPath(vector<vector<int>> &matrix, int sr, int sc, int er, int ec, int &maxSum, int countSum){
    if(sr == er && sc == ec){
        countSum += matrix[sr][sc];
        maxSum = max(maxSum, countSum);
        return;
    }

    if(sr > er || sc > ec)  return;

    // down
    if(sc < ec)
        maxSumPath(matrix, sr, sc+1, er, ec, maxSum, countSum+matrix[sr][sc]);
    // right
    if(sr < er)
        maxSumPath(matrix, sr+1, sc, er, ec, maxSum, countSum+matrix[sr][sc]);
    // diagonal
    if(sr < er && sc < ec)
        maxSumPath(matrix, sr+1, sc+1, er, ec, maxSum, countSum+matrix[sr][sc]);
}

//  ================== DP Solutions ================== //

// memoisation : bottom-up approach
// time : O(3^n) + ??
// space : O(n^2) + ??
int maxSumPathMemo(vector<vector<int>> &matrix, vector<vector<int>> &dp, int sr, int sc, int er, int ec, int maxSum, int countSum){
    // row ya col, indono me se jiske bhi end me poch jayenge, hm waha
    if(sr == er && sc == ec){
        dp[sr][sc] = matrix[sr][sc];

        // ** for visualization purposes only ** //
        // for(int i = 0; i < er; i++){
        //     for(int j = 0; j < ec; j++){
        //         cout << dp[i][j] << "\t";
        //     }
        //     cout << endl;
        // }
        // cout << "\n*********************************\n";

        return dp[sr][sc];
    }

    maxSum = dp[sr][sc];

    if(sr < er && sc < ec){
        int current_sum =
            max(maxSumPathMemo(matrix, dp, sr, sc+1, er, ec, maxSum, countSum),
                max(
                    maxSumPathMemo(matrix, dp, sr+1, sc+1, er, ec, maxSum, countSum),
                    maxSumPathMemo(matrix, dp, sr+1, sc, er, ec, maxSum, countSum)
                )
            );
        maxSum = matrix[sr][sc] + current_sum;
    }
    else if(sr == er)
        maxSum = matrix[sr][sc] + maxSumPathMemo(matrix, dp, sr, sc+1, er, ec, maxSum, countSum);
    else
        maxSum = matrix[sr][sc] + maxSumPathMemo(matrix, dp, sr+1, sc, er, ec, maxSum, countSum);

    dp[sr][sc] = maxSum;

    return maxSum;
}

// tabulation : top-down approach
// time  : O(n^2)
// space : O(n^2)
int maxSumPathDP(vector<vector<int>> &matrix, int rows, int cols){
    vector<vector<int>> storage(rows, vector<int>(cols, 0));

    storage[0][0] = matrix[0][0];

    // filling the first row and column
    for(int i = 1; i < rows; i++)   storage[0][i] += (storage[0][i-1] + matrix[0][i]);
    for(int i = 1; i < cols; i++)   storage[i][0] += (storage[i-1][0] + matrix[i][0]);

    for(int i = 1; i < rows; i++)
        for(int j = 1; j < cols; j++)
            storage[i][j] = max(storage[i-1][j], max(storage[i][j-1], storage[i-1][j-1]) ) + matrix[i][j];

    return storage[rows-1][cols-1];
}

// Driver function
int main(){
    vector<vector<int>> matrix({
                        {5, 6, 1, 7},
                        {-2, 10, 8, -1},
                        {3, -7, -9, 11},
                        {12, -4, 2, 6}
    });

    int rows = matrix.size();
    int cols = matrix[0].size();

    int maxSum = 0, countSum = 0;

    // recursive approach
    clock_t start = clock();
	maxSumPath(matrix, 0, 0, rows-1, cols-1, maxSum, countSum);
	clock_t end = clock();
    cout << maxSum << endl;
    // cout << "Recursion time : " << (start - end) << endl;

    // memoisation
    vector<vector<int>> storage(rows, vector<int>(cols, 0));

    clock_t start_2 = clock();
    cout << maxSumPathMemo(matrix, storage, 0, 0, rows-1, cols-1, maxSum, countSum) << endl;
    clock_t end_2 = clock();
    // cout << "Memoisation time : " << (start_2 - end_2) << endl;

    // tabulation
    cout << maxSumPathDP(matrix, rows, cols) << endl;

    return 0;
}
