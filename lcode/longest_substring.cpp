/*
 * =====================================================================================
 *
 *       Filename:  longest_substring.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2018 11:52:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std; 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int substr_start =0;
        int max_len =0 , cur_len =0;
        unordered_map<char, int> char_map;
        for (int i=0; i < s.length(); i++) {
            auto it = char_map.find(s[i]);
            if (it == char_map.end()) { /* not found previously */
                cur_len++;
                cout << "# char " << s[i] << " len " << cur_len << endl;
                char_map.insert(make_pair(s[i], i));
            } else {
                /* if found then remove the entry and re-add it */
                int str_len = i - substr_start;
                if (str_len > max_len) max_len = str_len;
                substr_start = it->second +1;
                char_map.erase(it);
                char_map.insert(make_pair(s[i], i));
                cur_len = i-substr_start+1;
                cout << " char " << s[i] << " len " << cur_len << endl;
            }
            
        }
        if (cur_len > max_len) max_len = cur_len;
        return max_len;
    }
};

int main (void) {
    Solution obj;
    cout << " len " <<obj.lengthOfLongestSubstring(string("abba")) << endl;

}
