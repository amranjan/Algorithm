/*
 * =====================================================================================
 *
 *       Filename:  add_number.cpp
 *
 *    Description:   Add two numbers represented by linked list
 *
 *        Version:  1.0
 *        Created:  08/07/2018 10:32:29 PM
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
    std::cout << "\n " << "Printing list   " << "\n";
    LIST *temp = head;
    while (temp != NULL) {
        std::cout <<  temp->val << "  ";
        temp = temp->next;

    }
}

LIST *add_numbers(LIST *number1, LIST *number2) {
    LIST *sum_number = NULL, *cur_ptr = NULL;
    LIST *n1 = number1, *n2 = number2;
    LIST *node = NULL;
    int carry=0, num1=0, num2=0, sum =0;
    while ((n1 != NULL) || (n2 != NULL)) {
        if (n1 != NULL) {sum += n1->val; n1= n1->next;}
        if (n2 != NULL) {sum += n2->val; n2=n2->next;}
        sum +=carry; carry =0;
        if (sum >=10) {sum = sum%10;carry =1; }


        /* Add in the sum_number   */
        node = create_node(sum);
        if (sum_number == NULL) { 
            cur_ptr = sum_number = node;
        } else { 
            cur_ptr->next = node;
            cur_ptr = node;
        }
        /*  make all Zero */
        sum = 0;
    }
    return sum_number;
}
int main (void) {

    LIST *head= NULL;
    int list1[] = {5,6,3};
    int list2[] = {8,4,2};
    LIST *number1 = create_list(list1, sizeof(list1)/sizeof(int));
    LIST *number2 = create_list(list2, sizeof(list2)/sizeof(int));
    LIST *number3 = add_numbers(number1, number2);
    print_list(number1);
    print_list(number2);
    print_list(number3);
    return 0;
}
