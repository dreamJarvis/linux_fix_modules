// https://www.interviewbit.com/problems/simple-queries/#include <bits/stdc++.h>
using namespace std;

bool sortDesc(const pair <int, int> &a, const pair <int, int> &b){
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
    // return a.first > b.first;
}

int power(long number, unsigned int power, int mod)
{
    long res = 1;
    number %= mod;
    while (power > 0) {
        if (power & 1)
            res = (res*number)%mod;

        power = power/2;
        number = (number*number) % mod;
    }
    return res;
}

int findNumberOfDivisors(int num){
    int cnt = 0;
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            // If divisors are equal,
            // count only one
            if (num / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

int productOfDivisors (int number) {
    int numberOfDivisors = findNumberOfDivisors(number);
    int mod = 1e9 + 7;
    if (numberOfDivisors & 1){
        number = sqrt(number);
    } else {
        numberOfDivisors = numberOfDivisors / 2;
    }
    return power(long(number), numberOfDivisors, mod);
}

vector<int> solve(vector<int> &A, vector<int> &B) {

    stack<int> s;
    vector<pair<long long, int>> maxStore (A.size(), make_pair(0, 0));
    // vector<int> res (B.size());

    for(int i=0; i < A.size(); i++){
        while (!s.empty() && A[i] > A[s.top()]){
            s.pop();
        }
        maxStore[i].first = (!s.empty() ? i - s.top() - 1 : i);
        maxStore[i].second = productOfDivisors(A[i]);
        // maxStore[i].second = A[i];
        s.push(i);
    }
    while (!s.empty()){
        s.pop();
    }

    for(int i = A.size() - 1; i >= 0 ; i--){
        while (!s.empty() && A[i] >= A[s.top()]){
            s.pop();
        }
        int tempVar = (!s.empty() ? s.top() - i - 1 : A.size() - i - 1);
        maxStore[i].first = (maxStore[i].first + 1) *(tempVar + 1);
        s.push(i);
    }

    sort(maxStore.begin(), maxStore.end(), sortDesc);
    // cout<<0<<" , "<<maxStore[0].second<<" , "<<maxStore[0].first<<"| ";

    for(int i = 1; i < maxStore.size(); i++){
        maxStore[i].first += maxStore[i-1].first;
        // cout<<i<<" , "<<maxStore[i].second<<" , "<<maxStore[i].first<<"| ";
        // if(i%10 == 0){
        //     cout<<endl;
        // }
    }
    // cout<<endl;
    vector<int> res (B.size(), maxStore[0].second);
    for(int i = 0; i < B.size(); i++){
        int mid = 0, low = 0, high = maxStore.size() -1;
        while (low <= high){
            mid = low + (high - low )/ 2;

            if(B[i] > maxStore[mid].first){
                low = mid + 1;
                if(B[i] > maxStore[mid].first && B[i] < maxStore[mid + 1].first){
                    res[i] = maxStore[mid + 1].second;
                    break;
                }
            } else if (B[i] < maxStore[mid].first) {
                high = mid -1;
                if(B[i] < maxStore[mid].first && B[i] > maxStore[mid - 1].first){
                    res[i] = maxStore[mid ].second;
                    break;
                }
            } else {
                res[i] = maxStore[mid].second;
                break;
            }
        }
    }

//     12 1 9 8 9 4 7 9 3 2 56 32 34
// 1 1
    return res;
}

// Driver funtion
int main(){

    return 0;
}
