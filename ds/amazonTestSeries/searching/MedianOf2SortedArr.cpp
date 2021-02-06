/*
    12. Median of 2 Sorted Arrays of Different Sizes
        https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/0/?track=amazon-searching&batchId=192

    leetcode : 4. Median of Two Sorted Arrays
        https://leetcode.com/problems/median-of-two-sorted-arrays/

    reference :
        https://www.youtube.com/watch?v=LPFhl65R7ww
*/
#include <bits/stdc++.h>
using namespace std;

// double util(vector<int> &a, vector<int> &b, int mIndex){
//     int n = a.size();
//     int m = b.size();
//
//     int i = 0, j = 0, k=0;
//     while(i < n && j < m){
//         if(a[i] < b[j]){
//             if(k == mIndex)
//                 return a[i];
//             k++;
//             i++;
//         }
//         else if(a[i] >= b[j]){
//             if(k == mIndex)
//                 return b[j];
//             k++;
//             j++;
//         }
//     }
//
//     while(i < n){
//         if(k == mIndex)
//             return a[i];
//         k++;
//         i++;
//     }
//
//     while(j < m){
//         if(k == mIndex)
//             return b[j];
//         k++;
//         j++;
//     }
//
//     return -1;
// }
//
// // O(n)
// // O(1)
// double MedianOfArrays(vector<int>& a, vector<int>& b){
//     int n = a.size();
//     int m = b.size();
//     int size = n+m;
//
//     bool isEven = true;
//     if(size%2){
//         isEven = false;
//     }
//
//     if(!isEven){
//         int pos = (n+m)/2;
//         return util(a, b, pos);
//     }
//     else{
//         int pos1 = (n+m)/2;
//         int pos2 = (n+m)/2-1;
//
//         int t1 = util(a, b, pos1);
//         int t2 = util(a, b, pos2);
//
//         double res = (float)(t1+t2)/2;
//         return res;
//     }
// }

// O(log(min(m,n))))
// O(1)
double MedianOfArrays(vector<int>& nums1, vector<int>& nums2){
    /*if nums1 size > nums2 size, then switch so that length of nums1 always < nums2*/
    if(nums1.size() > nums2.size()){
        return MedianOfArrays(nums2, nums1);
    }

    int x = nums1.size();
    int y = nums2.size();

    int low = 0;
    int high = x;
    while(low <= high){
        int partitionX = (low+high)/2;
        int partitionY = (x+y+1)/2-partitionX;

        // if partitionX is 0, it means there is nothing on left side, .'. use -INF
        /* if partitionX is == length of nums1, then it has reached the end of the elements, 
        ans there's nothing on the right side, .'. use +INF */
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX-1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        /* similar case for partitionY */
        int maxLefttY = (partitionY == 0) ? INT_MIN : nums2[partitionY-1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if(maxLeftX <= minRightY && maxLefttY <= minRightX){
            if((x+y)%2 == 0){
                return ((double)(max(maxLeftX, maxLefttY)+min(minRightX, minRightY))/2);
            }
            else{
                return ((double)max(maxLeftX, maxLefttY));
            }
        }
        else if(maxLeftX > minRightY)
            high = partitionX-1;
        else
            low = partitionX+1;
    }

    return -1;
}

// Driver function
int main(){
    // vector<int> a({1, 5, 9});
    // vector<int> b({2, 3, 6, 7});

    // vector<int> a({1, 2});
    // vector<int> b({3, 4});

    vector<int> a({1, 3});
    vector<int> b({2});

    double ans = MedianOfArrays(a, b);
    cout << ans << endl;

    return 0;
}
