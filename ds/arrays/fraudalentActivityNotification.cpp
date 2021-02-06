// hackerRank : Fraudulent Activity Notifications
// solution explanation : https://www.youtube.com/watch?v=46V6tnxy_Vs
#include <bits/stdc++.h>
using namespace std;

// returns the median for that window (trailing no of days)
double getMedian(vector<int> &countingSortList, int trailingDays, int medianPosition){
    // counter : sum's up the total no of element's it has recieved uptil this current elemetn, i.e by adding the frequency of all the number's upto this points
    // left : the current number
    int counter = 0, left = 0;

    // we will counter the total frequency in counter, and current number in left
    while(counter < medianPosition){
        counter += countingSortList[left];
        left += 1;
    }

    // step back one time
    int right = left;           // if the window has even no. we will have to get the next element
    left -= 1;                  // cause the above loop terminate's only when left crosses thershold, .'. -1

    // if odd , or both left and right of even are same
    if(counter > medianPosition || trailingDays%2 != 0)
        return left;
    else {
        // will keep traversing till we find the element next to the left, we had found
        while(countingSortList[right] == 0)
            right+=1;

        return (double)( (double)left + (double)right)/2;
    }
}

/*
    Information that we are given :
    1 ) array of interger,
    2 ) a fixed length i.e. trailing Days, after which we have to find if we should notify the customer or not
    3) and the max value limit that every i'th index will have is  == 200

    now, throuhout the array , we have to mainting an constant size of trailing days array in order to see that if we should notify the customer at (trailingDays + 1)'th day,

    so how do we do it ?
    we use something called window sliding technique, its just that for a gicen fixed length x, we will keep pushing the (x + i)'th value, and will keep deleting i'th value, so that the length remains constant, as given in the question

    Okay, so we now know how to keep the length constant,
    lets try the naive approach :
    let d = trailingDays

    so for every d size sub-array in the expenditure array, we will perform sorting, and then find medium
    so we have to perform sorting almost  (n-d) times
    given that the time complexity for sort() fun^n is O(nlog(n)), and performing it (n - 1) times
    our total time complexity : (n-1)*(nlog(n)) ~ O(n^2log(n))

    and we recieve TLE for this time complexity

    so now what ?
    we can reduce the time complexity, by using count-sort
    becuase it is given in the questions the the maximum value and item can have is <= 200, so as we are provided with a reasonable limit, we can apply count-sort whose time complexity is : O(n+k), i.e. linear

    but even if we apply count sort at evey loop while traversing the expenditure array, ww will still get a tc of O(n*(n+k)) ~ O(n^2), we will still get a TLE

    so , what should we do now ?
    well, there's a twist, we dont have to apply counting sort every time for next d-set of elments,
    if-fact using the concept of sliding window and counting-sort we can do it in O(n + constant )

    how do we do it ?
     |
     v
*/
int activityNotifications(vector<int> expenditure, int trailingDays){
    // initializing counting sort
    vector<int> countingSortList(201, 0);
    int end = trailingDays;                     // the size of the window we will be sliding

    // counting sort : counting the frequency of every number in the window provided
    for(int i = 0; i < end; i++)
        countingSortList[expenditure[i]]++;

    int current = 0;                        // index from where the window is starting
    int totalNotifications = 0;             //  total number of Notifications we will recieve

    // determine odd / even median positions
    int medianPosition = 0;
    if(trailingDays % 2 == 0)
        medianPosition = (int)trailingDays/2;
    else
        medianPosition = (int)trailingDays/2 + 1;

    int totalExpenditureLength = expenditure.size();

    // start and move expenditure list
    while(end < totalExpenditureLength){
        double median = getMedian(countingSortList, trailingDays, medianPosition);      // get's median

        // cout << expenditure[end] << "\t:" << round(median*2) << endl;

        // acc. to question
        if(expenditure[end] >= round(median*2))
            totalNotifications += 1;

        // modify the queue, first in first out
        // as we move along the window we will be moving the startign position .'. discarding the current values and including the end values
        countingSortList[expenditure[current]] -= 1;
        countingSortList[expenditure[end]] += 1;

        // sliding the window
        current += 1;
        end += 1;
    }

    return totalNotifications;
}

// Driver function
int main(){
    // vector<int> exp({10, 20, 30, 40, 50});
    // int d = 3;

    // vector<int> exp({2, 3, 4, 2, 3, 6, 8, 4, 5});
    // int d = 5;

    vector<int> exp({1, 2, 3, 4, 4});
    int d = 4;

    cout << activityNotifications(exp, d) << endl;

    return 0;
}
/*
5 4
1 2 3 4 4
*/
