/*
 * =====================================================================================
 *
 *       Filename:  clone_list.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/10/2018 07:18:35 AM
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
    struct _list *random;
} LIST;

LIST *create_node(int val) {
    LIST *temp = (LIST *)malloc(sizeof(int));
    if (temp != NULL) {
        temp->val = val;
        temp->next = NULL;
        temp->random = NULL;
        return temp;
    }
    return NULL;
}
LIST *create_list (const int *list, const int *random_ptr, int len)
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
    temp = head;
    LIST *next_ptr  = head;
    for (int i =1; i<len;i++) {
        for (int j=1;j<random_ptr[i];j++) {
            next_ptr = next_ptr->next;
        }
        temp->random = next_ptr;
        std::cout << "cur is " << temp->val << " " ;
        std::cout << "next ptr is  " << next_ptr->val << " " ;
        temp = temp->next;

        next_ptr = head;
        std::cout <<"\n";
    }
    return head;
}

void print_list(LIST *head) {
    std::cout << " Printing list   " << "\n";
    LIST *temp = head;
    while (temp != NULL) {
        std::cout << "  "<< temp->val ;
        temp = temp->next;

    }
#if 0
    std::cout << " \n";
    std::cout << " Printing list using random ptr   " << "\n";
    temp = head;
    while (temp != NULL) {
        std::cout << "  "<< temp->val ;
        temp = temp->random;
    }
#endif
    std::cout << " \n";
}
int main (void) {

    LIST *head= NULL;
    int list1[]  = {3,4,5,6,7,1,2};
    int random[] = {1,5,2,6,3,7,4};
    int nums[10] ={0};
    head = create_list(list1, random, sizeof(list1)/sizeof(int));
    /*  Reverse the list  */
    print_list(head);
    for (int i=0;i<10;i++) {
        std::cout << " "<< nums[i];
    }
}
