/*
 * =====================================================================================
 *
 *       Filename:  distinct_subsequence.cpp
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  09/13/2018 05:19:05 AM
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

    int numDistinct1(string s, string t) {
        int s_size = s.length() ;
        int t_size = t.length();
        vector <vector <int>> dp(s_size, vector<int>(t_size, 0));

        dp[s_size-1][t_size-1] = 0;
        if (s[s_size-1] == t[t_size-1]) {
            dp[s_size-1][t_size-1] = 1;
        }
        for (int i = s_size-1; i >= 0; i--) {
            for (int j = t_size-1; j >= 0; j--) {
                if (i<s_size-1) dp[i][j] = dp[i+1][j];
                if (s[i] == t[j]) {
                    /*  if the char matches then check the rest of the match  */
                    if ((i < s_size-1) && (j < t_size-1)) {
                        dp[i][j] += dp[i+1][j+1];
                    } else if ((j == t_size-1) && (i != s_size -1)) {
                        dp[i][j]++;
                    }

                }
            }
        }
        return dp[0][0];
    }
int numMatch(string s, string t, int s_idx, int t_idx) {
        int s_size = s.length() ;
        int t_size = t.length();
        cout << "calling numMatch"  << endl;
        int totalNum = 0;
        for (int i=s_idx;i<s_size ;i++) {
            if (s[i] == t[t_idx]) {
                if (t_idx == t_size-1) {
                    totalNum++;
                } else {
                //    if ((s_size -i) > (t_size - t_idx)) {
                        totalNum += numMatch(s, t, i+1, t_idx+1);
                        
                 //   }
                }
                
            } 
            
        }
        return totalNum;
    }
    int numDistinct(string s, string t) {
        return numMatch(s, t, 0, 0);
        
    }

int main (void) {
    string s("rabbbit");
    string t("rabbit");
    string s1("abcdeade");
    string t1("ad");
    cout << " Total match " << numDistinct1(s, t);
    cout << " Total match " << numDistinct1(s1, t1);
}
