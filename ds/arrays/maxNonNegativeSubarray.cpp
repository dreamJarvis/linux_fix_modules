#include <bits/stdc++.h>
using namespace std;

vector<int> maxset(vector<int> &arr) {
    int n=arr.size();

    int i=0, maxm=0, count=0, start=0, end=-1;
    int fstart=-1, fend=-1;

    long long int sum=0,maxsum=0;
    vector<int> res;

    while(i<n){
        if(arr[i]>=0){
            sum+=arr[i];
            count++;
            end++;
        }

        if(sum>maxsum){
            maxsum=sum;
            fstart=start;
            fend=end;
        }

        else if(sum==maxsum && count>maxm){
            maxm=count;
            fstart=start;
            fend=end;
        }

        if(arr[i]<0){
            count=0;
            start=i+1;
            end=i;
            sum=0;
        }

        i++;
    }

    if(fstart!=-1 && fend!=-1)
        for(int i=fstart; i<=fend; i++)
            res.push_back(arr[i]);

    return res;
}

int main(){
    vector<int> arr({-1, -1, -1, 2, 3, 5, 8,-2, 7, 23, -9, -9});

    for(auto value:maxset(arr))
        cout << value << " ";
    cout << endl;

    return 0;
}
