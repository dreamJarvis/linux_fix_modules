// 46. Permutations
#include <bits/stdc++.h>
using namespace std;

void permuteUTIL(string nums, string str, int pos){
    if(pos == nums.size()){
        cout << str << endl;
        // return ;
    }

    for(int i = pos; i < nums.size(); i++){
        swap(nums[pos], nums[i]);
        permuteUTIL(nums, str, pos+1);
        swap(nums[pos], nums[i]);
    }
}

void permute(string nums) {

    permuteUTIL(nums, "", 0);
    // return result;
}

// Driver function
int main(){
    string str = "00011101";
    permute(str);

    return 0;
}
