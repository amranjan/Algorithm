/*
 * =====================================================================================
 *
 *       Filename:  wildcardMatching.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/21/2018 08:33:01 PM
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
#include <vector>

using namespace std;

class Solution {
         
public:
    
    
    bool isMatch(string s, string p, int s_idx, int p_idx) {
        //printf(" Matching s[%d]=%c and p[%d]=%c\n", s_idx, s[s_idx], p_idx,p[p_idx]);
        /*  if s_idx is -1 and p_idx is -1 then return true */
        if (s_idx == -1) {
            if (p_idx == -1) return true;
            else if ((p_idx >= 0) && p[p_idx] == '*') {
                /*  If s_idx is -1 anmd p_idx is * then return 0 */
                return isMatch(s,p, s_idx, p_idx-1);
            } else {
                return false;
            }
        } else if ((s_idx >= 0) && (p_idx >= 0)) {
            if ((s[s_idx] == p[p_idx]) || (p[p_idx] == '?')) {
                return isMatch(s,p,s_idx-1,p_idx-1);
            } else if (p[p_idx] == '*') {
                for (int i=s_idx;i >= -1;i--) {
                    if (isMatch(s,p,i, p_idx-1)) return true;
                }
                /*  not partial s and p are not matching then return false. */
            }
        } 
        return false;

    }

    bool isMatch(string s, string p) {
        return isMatch(s,p, s.size()-1, p.size()-1);

    }
        
};



int main () {
    Solution obj;
    /*  
    string s = "abcde";
    string p = "ab*e";
    */
    //string p = "m??*ss*?i*pi";
    //string p = "m??*pi";
    //string p = "m??*ss*pi";
    //string p = "m??*ss*?i*pi";
    //string s = "mississippi";
    //string p = "m??*ss*i*pi";
    string s= "bbbababbabbbbabbbbaabaaabbbbabbbababbbbababaabbbab";
    //string p = "a******b*";
    string p =   "a**b*";

    cout << "found " << obj.isMatch(s , p) << endl;
}
