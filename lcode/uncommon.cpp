/*
 * =====================================================================================
 *
 *       Filename:  uncommon.cpp
 *
 *    Description:  Find uncommon words between  two sentences. 
 *    Solution : Store all the words in unordered map and keep adding number of times a word is found.
 *
 *
 *        Version:  1.0
 *        Created:  08/16/2018 07:13:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream> 
#include <utility>
#include <string>
#include <unordered_map>
#include <vector>

using word_count_t = std::unordered_map<std::string, int> ;
class Solution {
public:
    void add_word(std::string word, word_count_t &w_count) {
        auto it = w_count.find(word);
        if (it != w_count.end()) {
            it->second++;

        } else {

            auto et = std::make_pair(word, 1);
            w_count.insert(et);
        }
    }
    std::vector<std::string> uncommonFromSentences(std::string A, std::string B) {

        std::vector <std::string> uncommon_list;
        word_count_t words_list;

        std::string final_string(A);
        final_string.append(" "); 
        final_string.append(B); 
        std::string word;
        for (std::string::iterator it = final_string.begin(); it != final_string.end(); ++it) {
            if (!isalpha(*it)) { /*  if not alphabetic char */
                if (word.size() != 0) {
                    add_word(word, words_list);
                    word.clear();
                }
            } else {
                /*  If aplbhabetic char then add in the word */
                word.append(1, *it);
            }
        }
        add_word(word, words_list);
        /*  Now iterate throuh the list and find out each one of the count */
        std::cout << "uncommon words\n";
        for (auto it = words_list.begin(); it != words_list.end(); ++it) {
            auto u_it = uncommon_list.begin();
            if (it->second == 1) {
                u_it = uncommon_list.insert(u_it, it->first);
                std::cout << it->first << "\n";
            }
        }
        return uncommon_list;
    }
};

int main (void) {

    std::string a = "apple banana peach"; 
    std::string b = "apple orange grapes"; 
    Solution s;
    std::vector <std::string> final_words = s.uncommonFromSentences(a , b);


    return 0;
}
