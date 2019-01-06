/*
 * =====================================================================================
 *
 *       Filename:  valid_paranthesis.cpp
 *
 *    Description:  find the length of longest valid paranthesis in a string
 *    inout : ())()()()  output: 6
 *    input : ()())((()()(()()))) : 14
 *
 *        Version:  1.0
 *        Created:  09/10/2018 06:27:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int valid_para1(const char *a, int length) {
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
        cout << "length is " << dp[i]<< endl;
        if (max_len < dp[i]) {
            max_len = dp[i];
        }
    }
    return max_len;
}

int valid_para(const char *a, int length) {

    vector <int> v(length);
    int pairing=0;
    for (int i = 0; i<length;i++) {
        /*  Calculate the length of valid paranthesis from the index i */
        v[i]=0;
        pairing =0;
        int temp_len = 0;
        for (int j = i; j < length; j++) {
            if (a[j] == '(') {
                temp_len++;
                pairing++;
                if (pairing == 0) v[i] = temp_len;
            } else if (a[j] == ')') {
                pairing--;
                if (pairing < 0) {
                    /*  end of valid paranthesis */

                break;
                }
                temp_len++;
                if (pairing == 0) v[i] = temp_len;
            }
        }
    }
    int max_len =0;
    for (int i=0; i<length; i++) {
        cout << "length is " << v[i]<< endl;
        if (max_len < v[i]) {
            max_len = v[i];
        }
    }
    return max_len;
}

int main() {

    const char *in1 = "())()()()";
    const char *in2 = "()())((()()(()())))";
    const char *in3 = ")(((((()())()()))()(()))(";
    //cout << "length 1 "  << valid_para(in1, strlen(in1)) << endl;
    //cout << "length 2 "  << valid_para(in2, strlen(in2)) << endl;
    cout << "max length 3 "  << valid_para1(in3, strlen(in3)) << endl;
    return 1;
}
