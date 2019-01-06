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
#include <ctype.h>
#include <string.h>


typedef struct _stack_node {
    char val;
    struct _stack_node *next;
} STACK_NODE;


void print_stack(STACK_NODE *head) {
    std::cout << " Printing list   " << "\n";
    STACK_NODE *temp = head;
    while (temp != NULL) {
        std::cout << "Value : "<< temp->val << "\n  ";
        temp = temp->next;
    }
}

STACK_NODE *create_snode(int val) {
    STACK_NODE *temp = (STACK_NODE *)malloc(sizeof(STACK_NODE));
    if (temp != NULL) {
        temp->val = val;
        temp->next = NULL;
        return temp;
    }
    return NULL;
}
/*  Create stack from the list of nodes  */
bool push_node(STACK_NODE **head, char val )
{
    STACK_NODE *snode = create_snode(val);
    if (snode == NULL) {
        return false;
    }
    snode->next = *head;
    *head = snode;
    return true;
}

bool pop_node (STACK_NODE **head, char *val )
{
    STACK_NODE *snode = NULL;
    if ((head == NULL) || (*head == NULL)) return false;
    snode = *head;
    *head = snode->next;
    *val  = snode->val;
    free(snode);

    //std::cout << " pop number "<< *val<< "\n";
    return true;
}

STACK_NODE * create_stack(char *val, int len) {
    STACK_NODE *head = NULL;
    for (int i =0; i < len; i++) {
        push_node(&head, val[i]);
    }
    return head;
}

bool is_operator(char c) {
    if ((c == '+') || (c == '-') || (c == '*') ) {
        return true;
    }
    return false;
}
bool is_high_pr(char c , char b) {
    if (c == '*') return true;
    else  return false;
}


bool postfix_convert(char *infix, char *postfix) {
    STACK_NODE *head = NULL;
    int p_idx = 0;
    char op;
    if ((infix == NULL) || (postfix == NULL)) {
        return false;
    }
    /*  loop through all operators of infix */
    for (int i =0; i< strlen(infix); i++) {

        char c = infix[i];
        if (isdigit(c)) {
            postfix[p_idx++] = c;
        /*  if operator then  pop all higher precendence operator and enqueue */
        } else if (is_operator(c)) {
            while (pop_node (&head, &op))  {
                if (is_high_pr(op, c)) { /*  stack's op is higher then curent operator */
                    postfix[p_idx++] = op;
                } else { /*  push it back and break */
                    push_node(&head, op);
                    break; /*  if op is lower precendence than c then stop. */
                }
            } 
            /* higher operator is moved to postfix exp  */
            push_node(&head, c);
        } 
    }
    /*  now move all operator to postfix expr */
    while (pop_node(&head, &op)) {
        postfix[p_idx++] = op;
    }
    return true;
}

int main (void) {

    char infix[32] = "1+2*3";
    char postfix[32] = { 0 };
    STACK_NODE *stack = create_stack(infix, sizeof(infix)/sizeof(char) -1);
    char c ;
    postfix_convert (infix, postfix);
    while(1) {
        printf(" infix expr: %s postfix expr: %s \n", infix, postfix);
        memset(infix, 0, sizeof(infix));
        memset(postfix, 0, sizeof(postfix));
        std::cin >> infix;
        postfix_convert (infix, postfix);
        printf(" infix expr: %s postfix expr: %s \n", infix, postfix);
    }


    //print_stack(stack);
}
