/*
 * =====================================================================================
 *
 *       Filename:  longest_palin.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/11/2018 09:43:46 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string.h>

void print_substr(char *str, int s, int e) {
    std::cout << "\npalin is \n"; 
    for (int i = s;i<=e;i++)  {
        std::cout<<str[i];
    }
}
int longest_palindrome(char *str, int *first, int *last) {
    /*  once the char matches with previous char then save the cur ptr center. 
     *  rest the cur_palindrome size to 2.
     *
     *  start comaparing next char with prev char and 
     *  Reset the len of cur palindrome to 2, save the 
     *
     *  If cur match with prev and part  */

    int longest_palin = 1, l_start =0, l_end, cur_len =1;
    for (int i = 1; i < strlen(str); i++){
        if (str[i] == str[i-1]) { /*  compare with prev */
            /*  start of the palindrome */
            cur_len = 2;

            /* find the complete palindrome */
            int fwd_idx = i+1, back_idx = i-2;
            for (;fwd_idx <strlen(str) && back_idx >=0; fwd_idx++,back_idx--) {
                if (str[fwd_idx] == str[back_idx]) {
                    cur_len += 2;
                } else {
                    break;
                }
            }
            fwd_idx--; back_idx++;
            print_substr(str, back_idx, fwd_idx);
            if (cur_len > longest_palin) {
                longest_palin = cur_len;
                l_start = back_idx; l_end=fwd_idx;
            }
            cur_len = 0;
        }
    }
    return longest_palin;
}

int main(void) {

    char test_str[] = "FORGEEKSSKEESFOR";
    char test1_str[] = "FORGEEKSSKEEKSSKEE"; /*  first 8  14*/

    std::cout << "string : " << test_str << " palindrome :" << longest_palindrome(test_str, NULL, NULL) << "\n";
    std::cout << "string : " << test1_str << " palindrome :" << longest_palindrome(test1_str, NULL, NULL) <<"\n";


}
