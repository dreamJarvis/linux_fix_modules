/*
    library for min heap
*/
// ==============================  min Heap  ================================== //
struct MinHeapNode{
    int v;
    int key;
    MinHeapNode(int v, int key) : v(v), key(key) {}
};

struct MinHeap{
    int size;               // no. of nodes present currrently
    int capacity;           // capacity of min heap
    int *pos;               //needed for decrease key
    MinHeapNode **array;
    MinHeap(int capacity) : size(0), capacity(capacity), pos(new int[capacity]),
                            array(new MinHeapNode*[capacity]) {}
};

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b){
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap *minHeap, int idx){
    int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
		smallest = right;

	if (smallest != idx) {
		// The nodes to be swapped in min heap
		MinHeapNode* smallestNode = minHeap->array[smallest];
		MinHeapNode* idxNode = minHeap->array[idx];

		// Swap positions
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		// Swap nodes
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		minHeapify(minHeap, smallest);
	}
}

// if minHeap is is empty/not
bool isEmpty(MinHeap *minHeap){
    return (minHeap->size == 0);
}

MinHeapNode *extractMin(MinHeap *minHeap){
    if(isEmpty(minHeap))    return NULL;

    MinHeapNode *root = minHeap->array[0];

    MinHeapNode *lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // update position of the last node
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    // reduce the heap size and heapify root
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

/*
decrease key value of a given vertex v.
This function uses pos[] of min heap to get the current
index of the node in min heap
*/
void decreaseKey(MinHeap *minHeap, int v, int key){
    int i = minHeap->pos[v];
    minHeap->array[i]->key = key;

    /* Travel uo while complete tree is not heapified.
    This is a O(log(n)) loop
    */
    while(i && minHeap->array[i]->key < minHeap->array[(i-1)/2]->key){
        // swap this node with it's parent
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;

        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i-1)/2]);

        // move to parent index
        i = (i-1)/2;
    }
}

/*
    a utility function to check if a given vertex 'v' is in min heap or not
*/
bool isInMinHeap(MinHeap *minHeap, int v){
    if(minHeap->pos[v] < minHeap->size)
        return true;
    return false;
}
