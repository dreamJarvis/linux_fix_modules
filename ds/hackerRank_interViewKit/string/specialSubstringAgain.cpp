// hackerRank special substring again
// solution reference : https://www.youtube.com/watch?v=SJ_C9mclZJo
#include <bits/stdc++.h>
using namespace std;

/*
    conditions given :
    A string is said to be a special string if either of two conditions is met:
        1) All of the characters are the same, e.g. aaa.
        2) All characters except the middle one are the same, e.g. aadaa.


    method used :
        now there can be 2 types of string we can find, one where all the charecters are same,
        and other where the middle charecter is different

        1) where all the charecters are same in the string
            we count all the charecters and find the total no. of substrings that can be made
            by different combination of the charecters
            it is given easily by the formula : n*(n+1)/2
            where n = count of similar charecters

        2) where there is different middle charecter
            in this case, we know that we cant move the middle charecter anywhere,
            but the number of substrings formed will be how many similar charecter are appearing around that middle charecter,
            so we count how many of those are formed,
            in ordere to imagine it, imagine you throw a rock in a pond,
            now there will be ripples created, but it's center will always be the rock,
            in out case we are jut counting the ripples, and as we know in order for those ripples to be counted,
             * (as we go far from the center, the raduis will kepp on increasing )

            the charecter which are originally to the left, right of the middle charecter should be same,
            so as we go far from the middle charecter, we keep the charecters there at the edge by comparing it to the charecters,
            that were originally aroung the middle charecter,
            if they are the same, we keep on counting the ripples,
            if not, then we move on to find the next middle element,

            so, formulating what we discussed, if we have a string str, then, and we are at i'th index,
            with midlle element different, then
            we keep the the radius = 1;

            it tells us to check that if the element at the ripples edge is still same to the cherecters at the side of the middle element

            srt[i - radius] == str[i+1]     .. check the ripples left to the middle's right element
            str[i + radius] == str[i-1]     .. check the ripple right to the middle's left element

            ans += 1;

            until they differ, we keep the raduis increasing, and keep on adding to the answer
*/
long substrCount(int n, string str) {
    // cause we will include all the single charecters
    long totalCount = n;

    // this loop will count all the substring with same charecters and all the substring with different middle element
    for(int i = 0; i < n; i++){

        // to find the substring with all the same charecters
        int result=0;
        while(i+1 < n && str[i] == str[i+1]){
            result++;
            i++;
        }
        totalCount += (result * (result+1)/2) ;         // applying the formula to count all the substrings that are possible

        // to find all the substring whose middle element is different,
        // here we apply the ripples analogy we used above
        int ptr = 1;
        while(i - ptr >= 0 && i + ptr < n
                && str[i+ptr] == str[i-1]
                && str[i-ptr] == str[i+1]
        ){
            totalCount++;
            ptr++;
        }
    }

    return totalCount;
}

// Driver function
int main(){
    string str = "abcbaba";
    cout << substrCount(str.size(), str) << endl;
    return 0;
}
/*
asasd, 7
abcbaba, 10
aaaa, 10
*/
