/*
 * =====================================================================================
 *
 *       Filename:  list.cpp
 *
 *    Description:   *
 *        Version:  1.0
 *        Created:  08/02/2018 12:41:09 PM
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
#include <malloc.h>

typedef struct _list {
    int val;
    struct _list *next;
} LIST;

LIST *create_node(int val) {
    LIST *temp = (LIST *)malloc(sizeof(int));
    if (temp != NULL) {
        temp->val = val;
        temp->next = NULL;
        return temp;
    }
    return NULL;
}
LIST *create_list (const int *list, int len)
{
    if (list == NULL) return NULL;

    LIST *head = NULL, *temp = NULL, *curr = NULL;
    head = (LIST *)create_node(list[0]);

    curr = head;
    for (int i=1;i<len;i++) {
        temp = create_node(list[i]);
        curr->next = temp;
        curr= temp;
    }
    return head;
}

void print_list(LIST *head) {
    std::cout << " Printing list   " << "\n";
    LIST *temp = head;
    while (temp != NULL) {
        std::cout << "Value : "<< temp->val << "\n  ";
        temp = temp->next;

    }
}
/*  insert at a position pos start from 0  */
bool insert_at(LIST **head, int val, int pos) 
{
    if (head == NULL) return false;

    /*  IF nu element then store at the start */
    LIST *temp = *head;
    LIST *node = create_node(val);
    if (*head == NULL) {
        *head = temp;
        return true;
    }
    /*  IF pos is 0 then store at the start */
    if (pos == 0) {
        *head = node;
        node->next = temp;
    } else {
        for ( int i=0; i<pos -1 ;i++) {
            if (temp->next == NULL) {
                printf(" end of the list\n");
                break;
            }
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
    }
    return true;
}

bool insert1(LIST **head, int val) {
    if (head == NULL) return NULL;
    LIST *cur, *prev, *node;
    node = create_node(val);
    if (node == NULL)  return NULL;

    /* list is empty */
    if (*head ==NULL) {
        *head = node; 
        return true;
    }
    cur = *head;
    /*  if val is smallest */
    if (node->val < (*head)->val) {
        node->next = *head;
        *head = node;
        return true;
    }

    /*  if val exists in the middle */
    while (cur->next != NULL)  {
        if (cur->next->val > node->val) break;
        cur=cur->next;
    }
    node->next = cur->next;
    cur->next = node;
    return true;
}
bool insert(LIST **head, int val) {
    if (head == NULL) return false;
    LIST *cur, *prev, *node;
    node = create_node(val);
    if (node == NULL)  return false;

    cur = prev = *head;
    while (cur != NULL) {
        if (node->val < cur->val) {
            node->next = cur;
            if (cur == *head) {
                *head = node;
            } else {
                prev->next = node;
            }
            return true;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    /*  if not match then at the end */
    if (*head == NULL) 
        *head = node; 
    else {
        prev->next = node;
    }
    return true;
}

LIST * reverse(LIST **head) {

    if (head == NULL) return NULL;
    if ((*head == NULL ) || ((*head)->next == NULL)) return (*head); 
    LIST *cur = *head, *prev = NULL, *next = NULL;

    while (cur->next != NULL) {
        next = cur->next;
        cur->next = prev ;
        prev = cur;
        cur = next;
    }
    cur->next = prev;
    *head = cur;
    return (cur);
}


// Remove all nodes with val
bool remove(LIST **head, int val) {
    std::cout << "removing "<< val << "\n";
    if ((head == NULL)  || (*head == NULL)) return false;
    LIST *prev, *cur, *temp = NULL;
    prev = cur = *head;
    /*  Loop through the list and compare with the curr node
     *  if cur has the value then remove cur and replace current with cur->next */
    while (cur != NULL) {
        if (cur->val == val) {
            temp = cur;
            if (cur == *head) {
                /*  if cur is the head then move head to the next node alongwith prev ptr */
                *head = cur->next;
                cur = prev = *head;
            } else {
                /* if middle node has the value then just point prev->next  to the cur->next   */
                cur = cur->next;
                prev->next = cur;
            }
            free(temp);
        } else {
            /*  if no match then just move cur to next and prev to cur node */
            prev= cur;
            cur = prev->next;
        }
    }
    return true;
}

/*  Find nth from the end */
LIST *reverse_find(LIST **head, int pos) {

    if ((head == NULL) || (pos < 1)) return NULL;
    LIST *fwd_node = *head, *nxt_node = *head;
    int cnt = 1;

    while (fwd_node != NULL)  {
        fwd_node = fwd_node->next;
        if (cnt >= (pos+1)) {
            nxt_node = nxt_node->next;
        }
        cnt++;
    }
    if (pos > (cnt -1)) {
        std::cout << " Fewer elements than "<< pos << "\n";
        return NULL;
    }
    std::cout << "Node cval is " << nxt_node->val << "\n";
    return (nxt_node);
}
int main (void) {

    LIST *head= NULL;
    int list1[] = {3,4,5,6,7,1,2,3,4,4};
    int list2[] = {4};
    head = create_list(list1, sizeof(list1)/sizeof(int));
    /*  Reverse the list  */
    LIST *node4 = reverse(&head);
    print_list(head);

    LIST *node = reverse_find(&head, 4);
    LIST *node1 = reverse_find(&head, 0);
    LIST *node2 = reverse_find(&head, 10);
    LIST *node3 = reverse_find(&head, 11);
    
    //print_list(head);
    /*  test insert_at */
    head = create_list(list2, sizeof(list2)/sizeof(int));
    insert_at(&head, 10, 0);
    insert_at(&head, 9, 2);
    insert_at(&head, 8, 1);
    insert_at(&head, 7, 15);
    insert_at(&head, 6, 8);
    //print_list(head);

    /*  test insert */
    int list3[] = {4,6,7};
    head = create_list(list3, sizeof(list3)/sizeof(int));
    insert(&head, 9); // At end
    insert(&head, 5); // in the middle
    insert(&head, 2); // at the start
    print_list(head);
    /*  test remove */
#if 0
    int list4[] = {4, 4, 9, 7, 8, 8, 10, 10};
    head = create_list(list4, sizeof(list4)/sizeof(int));
    remove(&head, 4);
    print_list(head);
    remove(&head, 9);
    print_list(head);
    remove(&head, 10);
    print_list(head);
    remove(&head, 8);
    print_list(head);
    remove(&head, 6);
    print_list(head);
    remove(&head, 7);
    print_list(head);
#endif
    return 0;
}
