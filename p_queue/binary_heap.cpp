/*
 * =====================================================================================
 *
 *       Filename:  binary_heap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/28/2018 07:33:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


// A C++ program to demonstrate common Binary Heap Operations 
#include<iostream> 
#include<climits> 
using namespace std; 
  
// Prototype of a utility function to swap two integers 
void swap(int *x, int *y); 
  
// A class for Min Heap 
class MinHeap 
{ 
    int *harr; // pointer to array of elements in heap 
    int cap; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap 
public: 
    // Constructor 
    MinHeap(int capacity); 
  
    // to heapify a subtree with the root at given index 
    void MinHeapify(int ); 
  
    int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    int right(int i) { return (2*i + 2); } 
  
    // to extract the root which is the minimum element 
    int extractMin(); 
  
    // Decreases key value of key at index i to new_val 
    void decreaseKey(int i, int new_val); 
  
    // Returns the minimum key (key at root) from min heap 
    int getMin() { return harr[0]; } 
  
    // Deletes a key stored at index i 
    void deleteKey(int i); 
  
    // Inserts a new key 'k' 
    void insertKey(int k); 
}; 
  
MinHeap::MinHeap(int capacity) 
{
    cap = capacity;
    harr = new int[cap] ; 
    heap_size =0;
}
/*  Decreases value of the key at index i to new_val. 
 *  and then move it to its new position */
void MinHeap::decreaseKey(int i, int key) {
    harr[i] = key;
    /*  Now move it to its postion by swapping with parent */
    while ((i != 0) && (harr[i] < harr[parent(i)])) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

/*  Return the minimum value of key and remove from the heap */
int MinHeap::extractMin(void) {
    /*  remove the root and then move children up. */
    if ( heap_size <=0) {
        return INT_MAX; 
    }
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    int _key = harr[0];
    harr[0] = harr[heap_size-1]; 
    heap_size--;
    MinHeapify(0);
    return _key;
}

void MinHeap::deleteKey(int index) {
    int _key = harr[index];
    decreaseKey(index, INT_MIN);
    extractMin();
}
/*  First insert it at the end and move it up at its right position. */
void MinHeap::insertKey(int k) {
    if ( heap_size == cap) {
        return; 
    }
    /*  first add the key at the end */
    harr[heap_size++] = k;
    /*  Now move the key if smaller than its parent */
    int i = heap_size -1;
    while ( (i != 0) && harr[i] < harr[parent(i)]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }

}
/*  Check the root key against its left and right children and swap the smallest with  root position.
 *  Now repeat on same on the smallest node */
void MinHeap::MinHeapify(int root) {
    /*  find out the minimun among root and its left and right children  */
    int smallest = root;
    if ((left(root) < heap_size) && (harr[root] > harr[left(root)])) {
        smallest = left(root);
    } else if ((right(root) < heap_size) && (harr[smallest] > harr[right(root)])) {
        smallest = right(root);
    }
    if ( root != smallest) {
        swap(&harr[root], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x , int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {

    MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin();
    return 1;
}
