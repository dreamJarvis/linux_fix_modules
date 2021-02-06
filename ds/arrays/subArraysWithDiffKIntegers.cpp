// Sub-arrays with different k integers
// leetcode : 992 (unsolved)
#include <bits/stdc++.h>
using namespace std;

// TLE : O(n^2)
int subarraysWithKDistinct(vector<int>& arr, int k) {
    int n = arr.size();

    // to find the sub-arrays with k distinct integers
    int count = 0;
    for(int i = 0; i < n-1; i++){
        unordered_map<int, int> st;
        for(int j = i; j < n; j++){
            if(st.count(arr[j])) st[arr[j]]++;
            else                st[arr[j]] = 1;

            if(st.size()==k)        count++;
            else if(st.size() > k)  break;
        }
    }

    return count;
}

// O(n)
// sliding window technique
int subarraysWithKDistinct2(vector<int>& arr, int k) {
    int n = arr.size();

    unordered_map<int, int> visited;
    int ptr_1 = 0, ptr_2 = 0;
    int count = 0;

    while(ptr_2 < n){
        // visited.size() == k
            // ki agar ptr_2 add krne pr size() > k ho raha h toh ptr_1 subtract krdo
        if(visited.size() == k){
            count++;
            cout<<"\nmap : \n";

            // for(auto item:visited)
            //     cout << item.first << " --> " << item.second << endl;
            // cout << endl;

            if(!visited.count(arr[ptr_2])){     // ki ptr_2 add krne pr size bdh jayega
                if(visited[arr[ptr_1]]==0){
                    cout << "erasing : " << ptr_1 << endl;
                    visited.erase(arr[ptr_1]);
                }
                else
                    visited[arr[ptr_1]]--;

                cout << "size : " << visited.size() << "\t, ";
                cout << "removing : " << ptr_1 << "\t," << ptr_2 <<"\t = " << count << endl;

                ptr_1++;
                // continue;
            }
            else if(visited.count(arr[ptr_2])){
                cout << "adding : " << ptr_1 << "\t," << ptr_2 << "\t = "  << count << endl;

                visited[arr[ptr_2]]++;
                ptr_2++;
            }
            // cout << ptr_1 << "\t," << ptr_2 << "\t = " << count <<endl;
        }

        // visited.size() < k
            // ptr_2 add krte raho
        else if(visited.size() < k){

            cout << "adding : " << ptr_1 << "\t," << ptr_2 << "\t = " << count << endl;

            if(visited.count(arr[ptr_2]))
                visited[arr[ptr_2]]++;
            else
                visited[arr[ptr_2]] = 1;
            ptr_2++;

        }

        if(ptr_1 == ptr_2)
            ptr_2++;
    }

    return count;
}

// Driver function
int main(){
    vector<int> arr({1, 2, 1, 2, 3});
    // vector<int> arr({1,2,1,3,4});
    int k = 2;
    cout << subarraysWithKDistinct2(arr, k) << endl;
    return 0;
}
