/*
 * =====================================================================================
 *
 *       Filename:  find_median.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/26/2018 12:42:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;


// a = { 1,2,3,5,6,8}
// b = { 4,7,9,10}


int find_median(vector <int> &list1, vector<int> &list2) {

    int mid_idx = (list1.size() +  list2.size()) /2;
    int median_idx = 0;

    int idx1 =0, idx2=0;
    bool choose_1 = true;
    int index = 0;
    for (;(idx1<list1.size() && idx2 < list2.size());index++) {
        /*  Go upto mid_idx and then stop and return the current number  */
        if (list1[idx1] <= list2[idx2]) {
            if (index == mid_idx) return list1[idx1];
            idx1++;
        } else {
            if (index == mid_idx) return list2[idx2];
            idx2++;
        }

    }
    /*  either of the list is over  then just add the rest of the offset to the running list 
     *  and return the number */
    if (idx1 == list1.size()) {
        median_idx = idx2 + (mid_idx - index);
        return list2[median_idx];
    } else {
        median_idx = idx1 + (mid_idx - index);
        return list1[median_idx];
    }

}


int main (void) {

    vector <int> a = { 1,2,3,7,8};
    vector <int > b = {4,5,6,9,10,11, 13, 14, 15, 16};
    vector <int> c = {};
    vector <int> d = {1};

    vector <int> e = {1,2,3,4 };
    vector <int> f = {5,6,7,8,9};

    cout << find_median(a,b);
    cout << "\n";
    cout << find_median(c,d);
    cout << "\n";

    cout << find_median(e,f);
    cout << "\n";
}

