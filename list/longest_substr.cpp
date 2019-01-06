/*
 * =====================================================================================
 *
 *       Filename:  longest_substr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/11/2018 08:55:41 AM
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
int lengthOfLongestSubstring(char* s) {
    int last_pos[256] = {0}; /* init with -1 */
    for (int i =0;i<256;i++) last_pos[i] = -1;
    int start_pos =0/*start of substring*/ , cur_pos =0, longest_len =0, cur_len=0;
    for (int i=0;i < strlen(s);i++) {
        
        if (last_pos[s[i]] < start_pos) { /* if the char not found in the substring */
            cur_len++;
        } else { /* if char is found in the substring then update the len of sub string */
            cur_len = (i - last_pos[s[i]]);
            start_pos = last_pos[s[i]] +1;
            std::cout << "update the last position " <<  cur_len << "\n";
        }
        if (cur_len > longest_len) {
            longest_len = cur_len;
        }
        last_pos[s[i]] = i; /* update the last position of current char */
    }
    return longest_len;
}

int main (void) {
    char strings[] = "ABDEFGABEF";
    std::cout << "lenth of longest substring is " << lengthOfLongestSubstring(strings);
    std::cout << "\n";
}
