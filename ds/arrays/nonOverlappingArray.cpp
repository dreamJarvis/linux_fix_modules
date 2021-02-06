// Insert in sorted and non-overlapping interval array
#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// comparator : sorts the intervals according to their starting values
bool myComp(Interval a, Interval b){    return a.start < b.start; }

// merging overlapping intervals
vector<Interval> mergeOverlappingIntervals(vector<Interval> &intervals){
    // sorting the intervals according to theor starting point
    sort(intervals.begin(), intervals.end(), myComp);

    // container for storing the merged intervals
    vector<Interval> result;

    int n = intervals.size();
    result.push_back(intervals[0]);

    // we compare if the ith interval of the array overlaps with the latest element in the result..(i.e. jo value hmne sbse last me dali h issme.)
    // agar intervals array ki current i'th index wali value overlap kr rhi h result ke last value se ,toh hm result ke last value ko update kr denge.
    // agar interval array ki i'th index wali value ka overlap nhi h result ke last value se toh hm result me ith index ki intervals array ki value push kr denge
    for(int i = 1; i < n; i++){
        // yha hm check kr rhe h ki ith index wali value overlap kr rhi h ki nhi result ke last value se
        if(intervals[i].start <= result[result.size()-1].end)
            result[result.size()-1].end = max(result[result.size()-1].end, intervals[i].end);
        // agar overlap nhi krti toh push kr do result me.
        else
            result.push_back(intervals[i]);
    }

    return result;
}

// given an set of non-overlapping intervals, insert a new interval into the given intervals
vector<Interval> insertInOverlappingIntervals(vector<Interval> &intervals, Interval newInterval){
    int n = intervals.size();
    vector<Interval> result;
    result.push_back(intervals[0]);

    for(int i = 0; i < n; i++){
        if(intervals[i].start <= result[result.size()-1].end){
            result[result.size()-1].end = max(result[result.size()-1].end, intervals[i].end);
        }
        else
            result.push_back(intervals[i]);
    }

    return result;
}


void display(vector<Interval> &arr){
    for(auto value:arr)
        cout << value.start << " - " << value.end << endl;
    cout << endl;
}

// Driver function
int main(){
    vector<Interval> intervals_1, intervals_2;

    // input 1
    intervals_1.push_back(Interval(1, 2));
    intervals_1.push_back(Interval(3, 5));
    intervals_1.push_back(Interval(6, 7));
    intervals_1.push_back(Interval(8, 10));
    intervals_1.push_back(Interval(12, 16));

    cout << "input 1: \n";
    vector<Interval> result;
    result = mergeOverlappingIntervals(intervals_1);
    display(result);


    // input 2
    intervals_2.push_back(Interval(6, 8));
    intervals_2.push_back(Interval(1, 9));
    intervals_2.push_back(Interval(2, 4));
    intervals_2.push_back(Interval(4, 7));

    cout << "input 2: \n";
    result = mergeOverlappingIntervals(intervals_2);
    display(result);

    // inserting overlapping array
    cout << "inserting new interval in the intervals: \n";
    result = insertInOverlappingIntervals(intervals_1, Interval(4, 9));
    display(result);


    return 0;
}
