// leetcode : 88
#include <bits/stdc++.h>
using namespace std;

// to merge 2 soeted arrays
void mergeSortedArray(vector<int> &arr1, vector<int> &arr2){
    int i = 0,j = 0;

    if(m == 0)
        arr1 = arr2;
    else{
        for(i = 0; i < m+n; i++){
            if(j == n)
                break;
            else if(arr1[i] > arr2[j] || i >= m+j){  // i >= m+j, ka mtlb h ki jb arr1 ke sare elments place ho gaye h, ab bs arr2 ke elments bache hue h, jinko place krna h  
                arr1.insert(arr1.begin()+i, arr2[j++]);
            }
        }

        arr1.resize(m+n);
    }
}

// Driver function
int main(){
    vector<int> arr1({1, 2, 3});
    vector<int> arr2({2, 5, 6});

    mergeSortedArray(arr1, arr1.size() ,arr2, arr2.size());

    for(auto value:result)
        cout << value << " ";
    cout << endl;

    return 0;
}
