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
#include <vector>
using namespace std; 
  
// Prototype of a utility function to swap two integers 
  
struct MinHeapNode { 
    int val;
    int i; /*  index to the array  */
    int j; /*  index for the next element in the array */
    MinHeapNode(int _val, int array_idx, int ele_idx) : val(_val), i(array_idx), j(ele_idx) {}
    MinHeapNode(void) : val(0), i(0), j(0) {}

};

void swap(MinHeapNode *x, MinHeapNode  *y); 
/*  For merging K sorted array , 
 *  1. Build MinHeap from first element of all K arrays 
 *  2. Get the Min from heap and save in the first index of the 
 *     final array. 
 *  3. Add the next element from the same array which had Min Node in the heap
 *     and insert in the heap. 
 *
 *     if the array is empty then add INT_MAX in the heap and heapify again.
 *
 *
 *  */
// A class for Min Heap 
class MinHeap 
{ 
    MinHeapNode *harr; // pointer to array of elements in heap 
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
  
    // Returns the minimum key (key at root) from min heap 
    MinHeapNode getMin() { return harr[0]; } 
    // Inserts a new key 'k' 
    void insertKey(MinHeapNode &k); 
    void replaceMin(MinHeapNode &k) { harr[0] = k; MinHeapify(0); }
}; 
  
MinHeap::MinHeap(int capacity) 
{
    cap = capacity;
    harr = new MinHeapNode[cap] ; 
    heap_size =0;
}
/*  First insert it at the end and move it up at its right position. */
void MinHeap::insertKey(MinHeapNode &k) {
    if ( heap_size == cap) {
        return; 
    }
    /*  first add the key at the end */
    harr[heap_size++] = k;
    /*  Now move the key if smaller than its parent */
    int i = heap_size -1;
    while ( (i != 0) && harr[i].val < harr[parent(i)].val) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}
/*  Check the root key against its left and right children and swap the smallest with  root position.
 *  Now repeat on same on the smallest node */
void MinHeap::MinHeapify(int root) {
    /*  find out the minimun among root and its left and right children  */
    int smallest = root;
    int l = left(root);
    int r = right(root);
    //cout << " heapify " << harr[root].val << "  " ;
    if ((l < heap_size) && (harr[smallest].val > harr[l].val)) {
        smallest = l ;
    } if ((r <  heap_size) && (harr[smallest].val > harr[r].val)) {
        smallest =  r; 
    }
    if ( root != smallest) {
        swap(&harr[root], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(MinHeapNode *x , MinHeapNode *y) {
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}

void print_lists(vector <vector <int>> &arr) {
    for (int i =0; i < arr.size(); i++ ) {
        cout << "\n array " << i << " :";
        for (int j =0; j < arr[i].size(); j++) {
            cout << arr[i][j] << "  " ;
        }
    }
}
void print_final_list(vector <int> &arr) {
    cout << " \n merged arrary : ";
    for (int i =0; i < arr.size(); i++ ) {
        cout << arr[i] << "  ";
    }
    cout << endl;

}

int main(void) {

    vector <int> x1 = { 1,7,10,13};
    vector <int> x2 = { 3,8,12,15};
    vector <int> x3 = { 17,18,19,20};
    vector <int> x4 = { 4,16,21, 23};
    vector <int> x5 = { 6};
    vector <int> x6 = { 5,14,22, 24};

    /*  array of pointers to the vector of int */
    //vector <vector<int>> arr = {x1, x2, x3,x4, x5,x6};
    vector <vector<int>> arr = {x1, x2, x3, x4, x6};
    int total_num  = 0;
    print_lists(arr);

    /*  Here k = 6 */
    MinHeap h(arr.size()); 
    /* Add first element of all arrays    */
    for (int i = 0; i < arr.size(); i++ ) {
        total_num += arr[i].size();
        MinHeapNode node = MinHeapNode(arr[i][0], i, 1);
        h.insertKey(node);
    }

    vector <int > merged_arr (total_num);
    /*  now in the loop  */
    for(int i=0 ; i < total_num; i++) {
        /*  extract the min */
        MinHeapNode node = h.getMin();
        int arr_idx = node.i;
        int next_idx = node.j;
        merged_arr[i] = node.val;
        //cout << "min is " << node.val << " ";
        if (next_idx < arr[arr_idx].size() ) {
            node.val = arr[arr_idx][next_idx];
            node.j++; 
            //cout << " adding " << node.val << " \n";
        } else {
            node.val = INT_MAX;
        }
        h.replaceMin(node);
    }
    print_final_list(merged_arr);
}
