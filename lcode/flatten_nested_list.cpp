/*
 * =====================================================================================
 *
 *       Filename:  flatten_nested_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/06/2018 05:05:38 PM
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
#include <stack>

using namespace std;

 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
     int x;
     vector <NestedInteger> _list;
     bool is_int;
    public:
        NestedInteger(int i) : x(i) {
            is_int = true;
        }
        NestedInteger(vector <NestedInteger> l) : _list(l) {
            is_int = false;
        }
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const { return is_int;}
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const { return x;}
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const { return _list;}
      void print_all(void);
  };

void NestedInteger::print_all(void) {
    if (isInteger()) {
        cout << x << " ";
    } else {
        for ( auto it = _list.begin(); it != _list.end(); it++) {
            it->print_all();
        }
    }

}


class NestedIterator {
    int it_idx;
    const vector <NestedInteger> *It_list;
    struct obj_list_t { 
        int s_idx;
        const vector <NestedInteger>  *s_list;
        obj_list_t(int index, const vector <NestedInteger> *l) : s_idx(index), s_list(l) {}
    };
    stack <obj_list_t> _s;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        it_idx =0;
        It_list = &nestedList;
        findIntegerIdx();
    }
    /*  find the index to the class containing the integer 
     *  */
    void findIntegerIdx(void) {
        /*  if current element in list is Nested list then push the current list in the stack 
         *  and set the pointer to the first element of the internal list until the element 
         *  is an object of Integer type  */
        if (it_idx == It_list->size()) {
            /*  no more element in the current list. check in the stack */
            if (!_s.empty()) {
                auto temp = _s.top();
                _s.pop();
                it_idx = temp.s_idx +1;
                It_list = temp.s_list;
                findIntegerIdx();
            } else {
                it_idx = -1;
            }
        } else {
            /*  current list has mode elements. Check is the current element is list of integer */
            if (!(*It_list)[it_idx].isInteger()) {
                /*  current element is list then push the current list in the stack 
                 *  and  make the current element as current list */
                const vector <NestedInteger> *temp_list = &(*It_list)[it_idx].getList();
                if (temp_list->size() ==0) {
                    /*  current element is an empty list pass it on. */
                    it_idx++;
                    findIntegerIdx();
                } else {
                    /*  current element is non empty list */
                    obj_list_t temp(it_idx, It_list);
                    _s.push(temp);
                    It_list = temp_list;
                    it_idx = 0;
                    /*  Call the findIntegerIdx in case if the nested element is again an list */
                    findIntegerIdx();
                }
            }
        }

    }
    int next() {
        /*  current index points to the class containing integer. 
         *  Get the value and then find the next integer in the nested list of integers.
         *  IF there is no interger left in the list then set it to -1 */
        if ( it_idx == -1) return -1;
        int val = (*It_list)[it_idx++].getInteger();
        findIntegerIdx();
        return val;
    }

    bool hasNext() { return (it_idx != -1); }
        
};


int main (void) {
    vector <int> aa = { 1,2,3,4,5};
    vector <int> bb = { 6,7,8,9,10, 11};
    vector <NestedInteger> List;
    for (int i =0; i < aa.size(); i++) {
        List.emplace_back(aa[i]);
    }
    NestedInteger list1(List);

    vector <NestedInteger> List2;
    for (int i =0; i < bb.size(); i++) {
        List2.emplace_back(bb[i]);
    }
    NestedInteger list2(List2);
//    list1.print_all();

    vector <NestedInteger> final_list = { list1, list2};
    NestedInteger list_obj(final_list);
    list_obj.print_all();
    cout << endl;
    NestedIterator it_intg(final_list);
    while (it_intg.hasNext()) {
        cout << it_intg.next() << " ";
    }

    return 1;
}


