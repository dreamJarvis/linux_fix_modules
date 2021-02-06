/*
    Binary Heap
    youtube : https://www.youtube.com/watch?v=g9YK6sftDi0
    https://www.geeksforgeeks.org/binary-heap/
*/
#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y);

class MinHeap{
    int *harr;              //  pointer to array of elements in heap
    int capacity;           // maximum possible size of min heap
    int heapSize;           // current number of elements in min-heap

public:
    MinHeap(int capacity) : heapSize(0), capacity(capacity), harr(new int[capacity]) {}

    // re-arranges the elements of the heap, to it's original order
    void MinHeapify(int);       // O(log(n))

    // return the elements according to it's position
    int parent(int i)   { return (i-1)/2; }
    int left(int i)     { return (2*i + 1); }
    int right(int i)    { return (2*i + 2); }

    void display();
    int extractMin();
    void decreaseKey(int i, int newVal);
    int getMin()    { return harr[0]; }

    void deleteKey(int i);      // O(log(n))
    void insertKey(int k);      // O(log(n))
};

// insert a new key 'k'
// we replace the element , from bottom up , (bubbling upward)
void MinHeap::insertKey(int k){
    if(heapSize == capacity){
        cout << "\nOverflow : could not insert !\n";
        return ;
    }

    // first insert the new key value at the end
    heapSize++;
    int i = heapSize-1;
    harr[i] = k;

    // fix the min heap property if it is violated
    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// decrease value of key at index 'i' to newVal. It is assumed that newVal is smaller than harr[i]
void MinHeap::decreaseKey(int i, int newVal){
    harr[i] = newVal;

    // (newVal --> INT_MIN), .'. the top-most will be INT_MIN, then we will remove it,
    // leaving us with the, sorted heap
    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// to remove the min element (or root) from min heap
int MinHeap::extractMin(){
    if(heapSize <= 0)   return INT_MAX;
    if(heapSize == 1){
        heapSize--;
        return harr[0];
    }

    // store the min value, and remove it from the heap
    int root = harr[0];
    harr[0] = harr[heapSize-1]; // replace the top with the bottom-right most element
    heapSize--;                 // deleting the top element
    MinHeapify(0);              // heapify the remaining elements in heap

    return root;                // return the top element
}

void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();               // we delete the INT_MIN, from root, and the tree again bcomes min-sorted
}

// recursive method to heapify a subtree with root at a given index. This method assumes that the subtree is alrady heapified
void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l < heapSize && harr[l] < harr[i])
        smallest = l;
    if(r < heapSize && harr[r] <  harr[smallest])
        smallest = r;

    if(smallest != i){
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::display(){
    for(int i = 0; i < heapSize; i++)
        cout << harr[i] << " ";
    cout << endl;
}

// swap the element
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Driver function
int main(){
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);

    h.display();

    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    h.display();

    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();

    return 0;
}
