/*
 * =====================================================================================
 *
 *       Filename:  regularExp.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/2018 07:11:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Solution {
    bool isMatch(string s, string p, int s_idx, int p_idx) {
        //printf("s[%d]=%c p[%d]=%c\n", s_idx, s[s_idx], p_idx, p[p_idx]); 
        if ( s_idx == -1) {
            if (p_idx == -1) {
                /*  if both empty then return true */
                return true;
            } else if (p[p_idx] != '*') {
                /*  if s = "" and p="X" and X is not return false * */
                return false;
            } else {
                /*  s="" and p ="XXC*" then try matching s="" and p = "XX"  */
                return isMatch(s,p,s_idx, p_idx-2);
            }
        } else if (p_idx == -1) {
            /*  s non-empty and  p empty then return false*/
            return false;
        } else if ((p[p_idx] != '*') &&
                 ((p[p_idx] == '.') || (s[s_idx] == p[p_idx]))) {
            return isMatch(s,p,s_idx-1, p_idx-1);
        } else if (p[p_idx] == '*') {
            char star_char = p[p_idx-1]; // assuming there is a char before *
            int i = s_idx;
            if ((star_char == '.' ) || (s[i] == star_char)) {
                bool skip_cur_char = false;
                if (star_char == '.') skip_cur_char = true;
                while ( (i >= -1) && ((skip_cur_char) || (s[i] == star_char))) {
                    if (isMatch(s,p,i,p_idx-1)) {
                        return true;
                    }
                    i--;
                }
            }
            /* s[s_idx] is not star char C* */
            return isMatch(s,p,s_idx,p_idx-2);
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        return isMatch(s,p,s.size()-1, p.size()-1);
    }
}; 


int main() { 
    Solution obj;
    string s("aasdfasdfasdfasdfas");
    string p("aasdf.*asdf.*asdf.*asdf.*s");
    //string s("abcdabcds");
    //string p("abc.*abc.*s");
    cout << obj.isMatch(s,p) << endl;
}

