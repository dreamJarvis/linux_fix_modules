/*  leetcode : 80
    Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/
#include <bits/stdc++.h>
using namespace std;

// t : O(n)
// s : O(1)
int removeDuplicates1(vector<int>& arr) {
    int index = 0;
    bool flag = false;

    for(auto value:arr){
        if(index < 1 || (arr[index-1] < value ) || (arr[index-1] == value && flag) ){
            if(flag && value != arr[index-1]){
                arr[index++] = value;
            }
            else{
                arr[index++] = value;
                flag = flag^1;
            }
        }
    }

    return index;
}

// better solution : simple
// t : O(n)
// s : O(1)
int removeDuplicates2(vector<int>& nums) {
    int n = nums.size(), count = 0;

    // agar kisi array me ,agar i'th position wala element similar h, i'th - 2, mtlb current element se 2 peeche, (kyuki hme condition given h ki max. bs 2 repeating element ho skte h, aor kyuki array sorted h, toh ye toh guarenteed h ki sare repeating elements sath honge).
    // toh agar current position se 2 element peeche wala element similar h, toh hme usse consider nhi krna...
    // kisi bhi element ke kitne bhi repeatition ho skte h, toh hme pta kses lgega ki, hme new element jo honge wo currently placed elements se kitni doori pr rkhne h..
    // so hm kya krenge, ek count le lete h, jiska kaam hoga ki, kisi bhi element ke 2 repetition ke badh wo counter count krege ki hm j'th position se kitni door h..(j]th position wo position h jis se pehle hm repeating elements ke 2 elements rkh chuke h..aor koi bhi naye elements isske badh he rkenge..)
     // aor single elements ke liye ..hm jitni baar bhi chahe dekh le i'th - 2 position pr repeating element nhi milega, toh hm unhe phir insert kr denge
    for (int i = 2; i < n; i++){
        // agar 2 se zyada elements h kisi bhi element ke, toh count bdhate jayenge
        if (nums[i] == nums[i - 2 - count]){
            count++;
        }

        // toh jb agli baari naya element milega, toh hm unhe i'th position se (i'th - count) position pr rkhenge..kyuki hme previous elements ke 2 elements ko chd ke, usske sare repeatitions htane h, toh count un repetitions ka count rkhega..aor jb koi naya element aata h, toh wo usse i'th position se count distance peeche rkhta h
        else{
            nums[i - count] = nums[i];
        }
    }

    // count represent krta h total no. of repeating elements (excluding 2 repetitions), toh total length array ka hoga (length of original array(n)  - count)
    return (n - count);
}

// Driver function
int main(){
    // vector<int> arr({1,2});
    vector<int> arr({0,0,0,1,1,1,1,2,3,3,3,4,5});

    // removeDuplicates1(arr);

    int length = removeDuplicates2(arr);
    for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
