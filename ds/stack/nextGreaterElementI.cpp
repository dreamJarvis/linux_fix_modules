// next greater Element to the left inorder#include<bits/stdc++.h>
// References : https://www.geeksforgeeks.org/next-greater-element/
using namespace std;

// tc : O(n)
// using stack
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;

    /* we will initially assign every element in the map with -1,
    as later on when if the next greater element for that element is not available,
    we wont have to iterate again to assign -1 to it
    */
    for(auto i:nums2)
        mp[i] = -1;

    stack<int> s;
    for(int i = 0; i < nums2.size(); i++){
        if(s.empty() || i == 0){
            s.push(i);
            continue;
        }

        // here we will map the number with its next greater element
        while(!s.empty() && nums2[i] > nums2[s.top()]){
            mp[nums2[s.top()]] = nums2[i];
            s.pop();
        }

        s.push(i);
    }

    // finding the next greater element for every number in num1 in the map
    for(int i = 0; i < nums1.size(); i++){
        nums1[i] = mp[nums1[i]];
    }

    return nums1;
}

vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
   if(num1.size()==0)
       return {};

   vector<int> v(num2.size());
   int m = num2.back();
   map<int,int> mp;

   for(int i=0;i<num2.size();i++){
       mp[num2[i]]=i;
   }

   for(int i=0;i<num2.size();i++){
       v[i]=num2[i];
       for(int j=i+1;j<num2.size();j++){
           if(num2[j]>num2[i])
           {
               v[i]=num2[j];
               break;
           }
       }
   }

   vector<int> ans;
   for(auto i:num1) {
       if(v[mp[i]]==i)
           ans.push_back(-1);
       else ans.push_back(v[mp[i]]);
   }

   return ans;
}

int main(){
    // int arr[] = {1, 3, 2, 4};
    // int arr[] = {4, 3, 2, 1};
    int arr[] = {7, 8, 1, 4};

    int n = sizeof(arr)/sizeof(arr[0]);

    for(auto i:nextGreaterElement(arr, n))
        cout << i << " ";
    cout << endl;

    return 0;
}
