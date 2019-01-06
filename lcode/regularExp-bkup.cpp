/*
 * =====================================================================================
 *
 *       Filename:  regularExp-bkup.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/2018 02:37:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
    bool isMatch(string s, string p, int s_idx, int p_idx) {
        
        
        if ((s_idx == -1) && (p_idx == -1)) { 
            
            return true;
        } else if ((s_idx != -1) && (p_idx == -1)) {
            return false;
        } else if ((s_idx == -1) && (p[p_idx] == '*')) {
            return isMatch(s,p,s_idx, p_idx-2);
        } else if ((s_idx == -1) && (p[p_idx] != '*')) {
            return false;
        } else if ((p[p_idx] != '*') &&
                 ((p[p_idx] == '.') || (s[s_idx] == p[p_idx]))) {
            return isMatch(s,p,s_idx-1, p_idx-1);
        } else if (p[p_idx] == '*') {
            char star_char = p[p_idx-1]; // assuming there is a char before *
            int i = s_idx;
            if ((star_char == '.') || (s[i] == star_char)) {
                while ((i >= -1) && ((star_char == '.') || (s[i] == star_char))) {
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
