/*
 * =====================================================================================
 *
 *       Filename:  k_lists_merge.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/29/2018 09:16:05 PM
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


// * Definition for singly-linked list.
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 } ListNode;


ListNode *create_linkedList(vector <int> &a) {

    ListNode *head = new ListNode(a[0]);
    auto temp = head; 
    for (int i=1; i < a.size(); i++) {
        temp->next = new ListNode(a[i]);
        temp = temp->next;
    }
    return head;
}

void print_linkedList(ListNode *head) {
    auto temp = head;
    cout << endl;
    while (temp != NULL) {
        cout << temp->val << "  ";
        temp = temp->next;
    }
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *mergedList = NULL, *temp = NULL;

        int list_index =-1; 
        int smallest_val = 0;  //Assuming positive number otherwise use ffff
        int starting_index = 0;
        while(1) {
            int i=0;
            /*  Get the first none empty list */
            for (i =starting_index ; i < lists.size(); i++) {
                if (lists[i] != NULL)
                   break; 
            }
            if (i == lists.size()) return mergedList; /* Lists over  */

            smallest_val = lists[i]->val;
            starting_index = i;
            list_index = i;

            /*  Find out the smallest in the head os all lists */
            for (i =starting_index+1; i < lists.size(); i++) {
                if (lists[i] == NULL) continue;
                if (lists[i]->val < smallest_val) {
                    list_index = i; 
                    smallest_val = lists[i]->val;
                }
            }
            /*  Now add the smallest val in the merged list. */
            if (mergedList == NULL) {
                mergedList = temp = lists[list_index];
            } else {
                temp->next = lists[list_index];
                temp = temp->next;
            }
            lists[list_index] = lists[list_index]->next;
            temp->next = NULL;
        }

        return mergedList;
        
    }
    void mergeTwoList(ListNode **a, ListNode *b);

};
void Solution::mergeTwoList(ListNode **a, ListNode *b) {
    auto cur = *a;
    ListNode *temp = NULL, *prev = NULL;
    while ((b != NULL) && (cur != NULL)) {
        if (cur->val <= b->val) {
            prev = cur;
            cur = cur->next;
        } else {
            /*  else b node is smaller then move this node to list a at cur pos */
            temp = b;
            b = b->next;
            temp->next = cur;
            if (prev == NULL) {
                prev = *a = temp;
            } else {
                prev->next = temp;
                prev = temp;
            }
            
        }
    }
    if (cur == NULL) {
        if (prev != NULL) {prev->next = b; }
        else { *a=b; }
    }
}
int main(void) {

    vector<int > a = { 1,4};
    vector<int > b = { 2,3,5};
    vector<int > c = { 6,7,8};

    Solution s;
    vector <ListNode *> lists (3); 
     lists[0] = create_linkedList(a);
     lists[1] = create_linkedList(b);
     lists[2] = create_linkedList(c);
     for (auto list : lists) 
        print_linkedList(list);
     ListNode *merged = s.mergeKLists(lists);
     print_linkedList(merged);

    //s.mergeTwoList(list1, list2);


    return 1;
}


