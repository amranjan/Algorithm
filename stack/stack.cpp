/*
 * =====================================================================================
 *
 *       Filename:  stack.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/04/2018 05:14:29 PM
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

typedef struct _stack_node {
    LIST *node;
    struct _stack_node *next;
} STACK_NODE;

LIST *create_node(int val) {
    LIST *temp = (LIST *)malloc(sizeof(LIST));
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

STACK_NODE *create_snode(LIST *NODE) {
    STACK_NODE *temp = (STACK_NODE *)malloc(sizeof(STACK_NODE));
    if (temp != NULL) {
        temp->node = NODE;
        temp->next = NULL;
        return temp;
    }
    return NULL;
}
/*  Create stack from the list of nodes  */
bool push_node(STACK_NODE **head, LIST *NODE)
{
    STACK_NODE *snode = create_snode(NODE);
    if (snode == NULL) {
        return false;
    }
    snode->next = *head;
    *head = snode;
    return true;
}

bool pop_node (STACK_NODE **head, LIST **node)
{
    STACK_NODE *snode = NULL;
    if ((head == NULL) || (*head == NULL)) return false;
    snode = *head;
    *head = snode->next;
    *node  = snode->node;
    int val = (*node)->val;
    free(snode);

    std::cout << " pop number "<< val<< "\n";
    return true;
}
bool push(LIST **head , int val) 
{
    LIST *node = create_node(val);
    node->next = *head;
    *head = node;
    return true;
}

bool pop (LIST **head, int *val)
{
    if ((head == NULL) || (*head == NULL)) return false;
    LIST *node = *head;
    *head = node->next;
    *val = node->val;

    std::cout << " pop number "<< *val<< "\n";
    return true;
}

bool merge(LIST **first, LIST *second) {

    LIST *temp = *first;
    while (temp->next != NULL) {
        temp  = temp->next;
    }
    temp->next = second;
    return true;
}
/*  returns first common node between two lists */
LIST *find_merge_point(LIST *first, LIST *second) {
    STACK_NODE *first_stack  = NULL, *second_stack = NULL;
    LIST *temp =  first;
    while (temp != NULL) {
        push_node (&first_stack, temp);
        temp = temp->next;
    }
    temp =  second;
    while (temp != NULL) {
        push_node (&second_stack, temp);
        temp = temp->next;
    }

    temp = NULL; 
    LIST *first_node, *second_node;
    while ((first_stack != NULL) || (second_stack != NULL)) {
        pop_node(&first_stack, &first_node);
        pop_node(&second_stack, &second_node);
        if(first_node != second_node) {
            break;
        }
        temp = first_node; 
    }
    if (temp == NULL ) {
        std::cout << " there is no merge point " << "\n";; 
    } else {
        std::cout << " merge point is" << temp->val << "\n";; 

    }
}
int main (void) {

    LIST *head = NULL;
    int list1[] = {6,7,8,9,5};
    LIST *first = create_list(list1, sizeof(list1)/sizeof(int));
    int list2[] = {1,2};
    LIST *second = create_list(list2, sizeof(list2)/sizeof(int));
    int list3[] = {10,20};
    LIST *common = create_list(list3, sizeof(list3)/sizeof(int));
    int val;
#if 0
   val = pop(&head, &val);
   val = pop(&head, &val);
   val = pop(&head, &val);
   val = pop(&head, &val);
   push (&head, 3);
   push (&head, 4);
   push (&head, 5);
   push (&head, 6);
#endif
   //merge (&first, common);
  // merge (&second, common);
    print_list(first);
    print_list(second);
    find_merge_point(first, second);
}
