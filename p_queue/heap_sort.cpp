/*
 * =====================================================================================
 *
 *       Filename:  heap_sort.cpp
 *
 *    Description:  For heap sort, 
 *    binary heap is used for heap sort. 
 *    The definition or Binary heap: in case of Max Heap , Parent node of each 
 *    subtree in the binary heap is larger than its children. So root of 
 *    binary heap tree is always the maximum value. 
 *
 *    Deletion of Max Node: 
 *    remove the root node and move the last node to the root position.
 *     Then heapify again.
 *    
 *    Heapifying:
 *
 *    for Heapifying a node in the binary heap, Compare the root node
 *     against its children and replace it with the maximmum of its children. 
 *     After swaping, Call heapifying again the child node where the element is moved. 
 *
 * To Implement heap sort, 
 * Heapify all the non-leaf starting from last non-leaf node to the first node. 
 * Once done. Max element goes to the root. 
 * Now move the Max element to the last element and then move the 
 * second last element to the root position and them heapify the root element. 
 *
 *
 *                   
 *
 *        Version:  1.0
 *        Created:  11/27/2018 10:46:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int left(int i) { return (2*i+1);}
int right(int i) {return (2*i+2);}
int parent(int i) {return (i-1)/2;}
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void MaxHeapify(int a[], int index, int size) {
    /* find the max among root, let and right and then swap the max with root */
    int l, r, max = index;
    l = left(index); 
    r = right(index);

    if ((l< size) && (a[l] > a[max])) max = l;
    if ((r < size) && (a[r] > a[max])) max = r;
    /*  swap max with root */
    if (index != max) {
        swap(&a[index], &a[max]);
        MaxHeapify(a, max, size);
    }
}

void heap_sort(int a[], int size) {
    /*  First Heapify all non-leaf  */
    for (int i = (size-1)/2; i >=0;i--) {
        MaxHeapify(a, i, size);
    }
    /*  Now move the first element to the last element and heapify the array again  */
    /*  So each iteration will move the largest element to the last location
     *  and them bring the max element to the 0th index by doing MaxHeapify  */
    for (int i=size-1; i>=1; i--) {
        swap(&a[0], &a[i]);
        MaxHeapify(a, 0, i);
    }
}

/*   */
int main(void) {
    int aa[6] = {5,6,3,4,1,9};
    heap_sort(aa, 6);
    cout << " \n";
    for (int i=0;i<6; i++) {
        printf("%d " , aa[i]);
    }

    return 1;

}
