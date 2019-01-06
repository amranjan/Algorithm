/*
 * =====================================================================================
 *
 *       Filename:  generateParanthesis-rec.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/03/2018 12:23:19 AM
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
#include <set>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string > paran_list; 
        if (n == 0) return (paran_list);
        if (n == 1) {
            paran_list.emplace_back("()");
            return paran_list;
        }
        vector <string> prev_list = generateParenthesis(n-1);
        set <string > _list;
        for (auto it = prev_list.begin(); it != prev_list.end(); it++) {
            string temp = *it;
            for (int i=0; i <=it->size(); i++) {
                temp.insert(i, string("()"));
                _list.insert(temp);
                temp = *it;
            }
        }
        for (auto it = _list.begin(); it != _list.end(); it++) {
            paran_list.push_back(*it);
        }
        return paran_list;
    }

};


int main(void ) {
    Solution obj; 

    vector <string> x = obj.generateParenthesis(4);
    for (auto s : x ) {
        cout << s << "  ";
    }
    cout << endl;
}

