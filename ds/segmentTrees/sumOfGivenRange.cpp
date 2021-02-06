// sum of given range
/*
    References :

    https://www.youtube.com/watch?v=2bSS8rtFym4&t=3s
    https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/?ref=rp
*/
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------ using Brute Force ---------------------------
// query sum: O(Q*N), (Q - number of queries)
// update : O(1)
class SumOfGivenRangeI{
    vector<int> arr;
    int n;
public:
    SumOfGivenRangeI(const vector<int> arr){
        this->arr = arr;
        this->n = arr.size();
    }

    // range sum
    int querySum(int l, int r);
    void update(int index, int value);
    void display();
};

// returning sum of the query
int SumOfGivenRangeI::querySum(int l, int r){
    int sum=0;
    for(int i=l-1; i <=r-1; i++)
        sum += arr[i];
    return sum;
}

// updating of query
// tc : O(1)
void SumOfGivenRangeI::update(int index, int value){
    if(index-1 >= 0 && index-1 < n)
        arr[index-1] = value;
    else
        cout << "Invalid index" << endl;
}

void SumOfGivenRangeI::display(){
    for(auto i:arr)
        cout << i << ", ";
    cout << endl;
}


//------------------------------- Using Efficient Method ------------------------------
// query sum : O(N)
// update : O(N*Q), (Q - number of queries)
class SumOfGivenRangeII{
    vector<int> originalArr;
    vector<int> rangeQueryArr;
    int n;
public:
    SumOfGivenRangeII(vector<int> arr){
        this->originalArr = arr;
        this->n = arr.size();

        vector<int> temp(n, 0);
        temp[0] = originalArr[0];
        for(int i = 1; i < n; i++)
            temp[i] += (temp[i-1] + originalArr[i]);

        this->rangeQueryArr = temp;
    }

    int querySum(int l, int r);
    void update(int index, int value);
    void display();
};

int SumOfGivenRangeII::querySum(int l, int r){
    if(l>=0 && r < n)
        return (l-2 >= 0 ? (rangeQueryArr[r-1] - rangeQueryArr[l-2]) : rangeQueryArr[r-1] );
    return -1;
}

void SumOfGivenRangeII::update(int index, int value){
    int diff = value - originalArr[index-1];
    originalArr[index-1] = value;

    if(diff >= 0){
        for(int i = index-1; i < n; i++){
            rangeQueryArr[i] += diff;
        }
    }
    else{
        for(int i = index-1; i < n; i++){
            rangeQueryArr[i] -= diff;
        }
    }
}

void SumOfGivenRangeII::display(){
    for(auto i:originalArr)
        cout << i << ", ";
    cout << endl;
}

//---------------------------------------- Segment Tree aprroach ------------------------------------//
// tc for sum of range    : O(lon(n))
// tc for updated         : O(lon(n))
class SumOfGivenRangeIII{
    int n;
    vector<int> originalArr;
    vector<int> segmentTree;
public:
    // contruction of segment tree
    SumOfGivenRangeIII(vector<int> arr){
        this->originalArr = arr;
        this->n = arr.size();

        // calculating the size of segment tree
        int height = (int)(ceil(log2(n)));
        int treeSize = 2*(int)pow(2, height) - 1;

        vector<int> temp(treeSize, 0);
        this->segmentTree = temp;

        constructBT(0, n-1, 0);
    }

    // constucts the segmented tree
    int constructBT(int ss, int se, int si);

    // sum range query
    int rangeSumQueryUtil(int ss, int se, int qs, int qe ,int si);
    int rangeSumQuery(int qs, int qr);

    // update query
    void updateValue(int index, int value);
    void updateValueUtil(int ss, int se, int si, int index, int diff);

    // display
    void display();
};

// constucts the segmented tree
int SumOfGivenRangeIII::constructBT(int ss, int se, int si){
    // when we reach the end of the tree, we start insertign elements to the leaf nodes
    if(ss == se){
        segmentTree[si] = originalArr[ss];
        return originalArr[ss];
    }

    int mid = (ss + (se - ss)/2 );
    segmentTree[si] = constructBT(ss, mid, 2*si+1) + constructBT(mid+1, se, 2*si+2);

    return segmentTree[si];
}

// range - sum
int SumOfGivenRangeIII::rangeSumQueryUtil(int ss, int se, int qs, int qe ,int si) {
    // total overlap
    if(qs <= ss && qe >= se)
        return segmentTree[si];

    // no overlap
    if(qs > se || qe < ss)
        return 0;

    int mid = (ss + (se - ss)/2);             // to avoid overflow

    // cout << "sum" << endl;
    return  (   rangeSumQueryUtil(ss, mid, qs, qe, 2*si+1) +
                rangeSumQueryUtil(mid+1, se, qs, qe, 2*si+2)
            );
}

int SumOfGivenRangeIII::rangeSumQuery(int qs, int qe){
    qs--;
    qe--;
    if(qs < 0 || qe > n-1)
        return -1;

    return rangeSumQueryUtil(0, n-1, qs, qe, 0);
}

// Update query
void SumOfGivenRangeIII::updateValueUtil(int ss, int se, int si, int index, int diff){
    // if index doesn't lies in the range
    if(index < ss || index > se)
        return ;

    // add the difference to all those values whcih lies in the range of index
    segmentTree[si] += diff;
    if(ss != se){
        int mid = (ss + (se - ss)/2);
        updateValueUtil(ss, mid, 2*si+1, index, diff);
        updateValueUtil(mid+1, se, 2*si+2, index, diff);
    }
}

void SumOfGivenRangeIII::updateValue(int index, int value){
    index--;
    if(index < 0 || index > n-1){
        cout << "Invalid index" <<endl;
        return ;
    }

    int diff = value - originalArr[index];
    originalArr[index] = value;

    updateValueUtil(0, n-1, 0, index, diff);
}

// display the segment tree
void SumOfGivenRangeIII::display(){
    for(auto i:originalArr)
        cout << i << ", ";
    cout << endl;

    cout << "\nsegment Tree : \n";
    for(auto i:segmentTree)
        cout << i << ", ";
    cout << endl;
}

// Driver function
int main(){
    // vector<int> arr({1,  3, 5, 7, 9, 11});
    // SumOfGivenRangeI obj(arr);
    //
    // cout << obj.querySum(1, 3) << endl;
    // obj.update(2, 10);
    // obj.display();
    // cout << obj.querySum(1, 3) << endl;

    // vector<int> arr({1,  3, 5, 7, 9, 11});
    // SumOfGivenRangeII obj(arr);
    //
    // cout << obj.querySum(1, 3) << endl;
    // obj.update(2, 10);
    // obj.display();
    // cout << obj.querySum(1, 3) << endl;


    // segment tree Method
    vector<int> arr({1,  3, 5, 7, 9, 11});
    SumOfGivenRangeIII obj(arr);
    // obj.display();
    cout << obj.rangeSumQuery(1, 3) << endl;
    obj.updateValue(2, 10);
    cout << obj.rangeSumQuery(1, 3) << endl;

    return 0;
}
