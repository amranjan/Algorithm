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
        ListNode *mergedList = NULL;
        for (auto list : lists ) {
            mergeTwoList(&mergedList, list);
            print_linkedList(mergedList);
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


