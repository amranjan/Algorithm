/*
 * =====================================================================================
 *
 *       Filename:  editDistance.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/11/2018 02:22:53 PM
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
#include <string>
#include <climits>

using namespace std;

int min(int a,int b,int c) {
    int temp = (b< c ? b : c);
    return (a < temp ? a: temp);
}
class Solution {
public:
    int getMinDistance(string &word1, string &word2, int idx1, int idx2, int cur_distance) {
        if (word1[idx1] == word2[idx2]) {
            /* this char is matching then check next char */ 
            if ((idx1==0) && (idx2==0)) { return cur_distance;}
            if ((idx1>0) && (idx2>0)) {
                return getMinDistance(word1, word2, idx1-1, idx2-1, cur_distance);    
            } else if (idx1==0){
                /* word1 is over. rest of the char in word2 should be removed */
                return (cur_distance +idx2);
            } else if (idx2== 0) {
                /* word1 is over. rest of the chars in word1 should be inserted in word1 */
                return (cur_distance +idx1);
            }
        }else {
            /* cur chars are not matching */
            int replace_char =INT_MAX, insert_char =INT_MAX , del_char =INT_MAX;
            if ((idx1 ==0) && (idx2==0)) { return (cur_distance+1);}
            /* replace cur chars and calculate */
            if ((idx1 >0) && (idx2 > 0)) {
                replace_char = getMinDistance(word1, word2, idx1-1, idx2-1, cur_distance);
            }
            if (idx1>0) {
                insert_char = getMinDistance(word1, word2, idx1-1, idx2, cur_distance);
            }
            if (idx2 > 0) {
                del_char = getMinDistance(word1, word2, idx1, idx2-1, cur_distance);
            }
            return (min(replace_char, insert_char, del_char) +1);
        }
        return cur_distance;
    }
    int minDistance(string word1, string word2) {
        if (word1.empty() && word2.empty()) return 0;
        if (word1.empty()) return word2.length(); // delete all word2 chars 
        if (word2.empty()) return word1.length();  // add all word1 chars
        /* Start from the end and keep calculating */
        return getMinDistance(word1, word2, word1.length()-1, word2.length()-1, 0);
    }
};

class Solution1 {
public:
    int getMinDistance(string &word1, string &word2, int idx1, int idx2, int cur_distance) {
        if (word1[idx1] == word2[idx2]) {
            /* this char is matching then check next char */ 
            if ((idx1==0) && (idx2==0)) { return cur_distance;}
            if ((idx1>0) && (idx2>0)) {
                return getMinDistance(word1, word2, idx1-1, idx2-1, cur_distance);    
            } else if (idx1==0){
                /* word1 is over. rest of the char in word2 should be removed */
                return (cur_distance +idx2);
            } else if (idx2== 0) {
                /* word1 is over. rest of the chars in word1 should be inserted in word1 */
                return (cur_distance +idx1);
            }
        }else {
            /* cur chars are not matching */
            int replace_char =INT_MAX, insert_char =INT_MAX , del_char =INT_MAX;
            if ((idx1 ==0) && (idx2==0)) { return (cur_distance+1);}
            /* replace cur chars and calculate */
            if ((idx1 >0) && (idx2 > 0)) {
                replace_char = getMinDistance(word1, word2, idx1-1, idx2-1, cur_distance);
            }
            if (idx1>0) {
                insert_char = getMinDistance(word1, word2, idx1-1, idx2, cur_distance);
            }
            if (idx2 > 0) {
                del_char = getMinDistance(word1, word2, idx1, idx2-1, cur_distance);
            }
            return (min(replace_char, insert_char, del_char) +1);
        }
        return cur_distance;
    }
    int minDistance(string word1, string word2) {
        if (word1.empty() && word2.empty()) return 0;
        if (word1.empty()) return word2.length(); // delete all word2 chars 
        if (word2.empty()) return word1.length();  // add all word1 chars
        /* Start from the end and keep calculating */
        char dp [word2.length()][word1.length()];
        for (int idx2 = 0 ; idx2 < word2.length(); idx2++) {
            for (int idx1 = 0; idx1 < word1.length(); idx1++) {
                if (word1[idx1] == word2[idx2]) {
                    /* check if this is first char in both or either */
                    if ( (idx1 == 0) && (idx2== 0)) {
                        dp[idx2][idx1] = 0;
                    } else if ((idx1 == 0) && (idx2 > 0)) {
                        dp[idx2][idx1] = idx2;
                    } else if ((idx1 > 0) && (idx2 == 0)) {
                        dp[idx2][idx1] = idx1;
                    } else {
                        /*  both are non 0 index */
                        dp[idx2][idx1] = dp[idx2-1][idx1-1];
                    }
                } else {
                    /*  non matching char */
                    int replace_char = INT_MAX, insert_char =INT_MAX , del_char =INT_MAX;
                    if ((idx2 == 0)  && (idx1 ==0)) {
                        dp[idx2][idx1] = 1;
                    } else {
                        if ((idx2 >0) && (idx1 > 0)) replace_char = dp[idx2-1][idx1-1] +1;
                        if (idx2 >0) del_char = dp[idx2-1][idx1] +1;
                        if (idx1 >0) insert_char = dp[idx2][idx1-1] +1;
                        dp[idx2][idx1] = min(replace_char, insert_char, del_char);
                    }
                }
            }
        }
        return dp[word2.length()-1][word1.length()-1];
    }
};

int main() {
    Solution1 obj;
    string word1 = "horse";
    string word2 = "ros";

    cout << "min edit distance "<< obj.minDistance(word1, word2) << endl;

    return 1;
}
