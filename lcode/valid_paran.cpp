/*
 * =====================================================================================
 *
 *       Filename:  valid_paran.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/11/2018 07:24:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string a) {
        int length = a.length();
        vector <int> dp(length);
        /*  dp[i] contains the max length of valid parantheses ending at i */
        dp[0] = 0;
        for (int i=1; i < length; i++) {
            if (a[i] == '(') {
                dp[i] = 0;
            } else if (a[i] == ')') {
                /*  check previous char */
                if (a[i-1] == '(') {
                    /*  { i-1, i } = ()  */
                    dp[i] = 2;
                    if ((i-1) > 0) {
                        dp[i] += dp[i-2];
                    }
                } else {
                    /*  i-1 is ')' */
                    /*       02002048 */
                    /*  case ()(()()) i = 7  dp[7] = 4+ 2 + 2 if a[7-4-1] == (*/
                    if ((i - dp[i-1] > 0) && (a[i- dp[i-1] -1] == '(')) {
                        dp[i] = dp[i-1]+2;
                        if (i-2-dp[i-1] > 0) {
                            dp[i] += dp[i-2-dp[i-1]];
                        }
                    } else { 
                    /*  case ())()()) i = 7  dp[7] = 4+ 2 + 2 if a[7-4-1] != (*/
                        dp[i] = 0;
                    }

                }
            }
        }

        int max_len =0;
        for (int i=0; i<length; i++) {
            if (max_len < dp[i]) {
                max_len = dp[i];
            }
        }
        return max_len;

        
};
