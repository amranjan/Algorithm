/*
 * =====================================================================================
 *
 *       Filename:  remove_char.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2018 05:30:00 PM
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
using namespace std;

/*  Remove all characters matching with c in the string str */
bool remove_char(char *str, char c)  {
    int     move_count =0;
    for (int i =0; i < strlen(str); i++) {
        if (str[i] == c) {
            move_count++;
        } else if (move_count > 0) {
            str[i-move_count] = str[i];
        }
    }
    str[strlen(str)-move_count] = '\0';
    if (move_count) {
        return true;
    }
    return false;;
}


bool remove_char(string &str, char c) {
    int move_count =0;
    for (auto it = str.begin();it != str.end();it++) {
        if 


    }
}
int main(void) {

    char sss[] = "AABDCEDB";
    cout << remove_char(sss, 'B') << endl;
    cout << remove_char(sss, 'A') << endl;
    cout << sss;
    return 1;
}

