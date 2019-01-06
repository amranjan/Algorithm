
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        /* for generating n pairs first generate 1 to n-1 */ 
        vector<set <string>> paran(n);
        string temp("()");
        //cout << temp << "  ";
        paran[0].insert(temp);
        for (int i=1; i < n; i++) {
            
            for (auto it =paran[i-1].begin(); it != paran[i-1].end() ; it++) {
                string temp("()");
                temp.insert(2, *it);
                //cout << temp << "  ";
                paran[i].insert(temp);
                temp = string("()");
                temp.insert(1, *it);
                //cout << temp << "  ";
                paran[i].insert(temp);
                temp = string("()");
                temp.insert(0, *it);
                //cout << temp << "  ";
                paran[i].insert(temp);
            }
        }
        
        vector <string > _list; 
        cout << endl;
        for (auto it = paran[n-1].begin(); it != paran[n-1].end(); it++) {
            //cout << *it << "  " ;
            _list.push_back(*it);
        }
        return _list;
    }
};

int main(void ) {
    Solution obj; 

    vector <string> x = obj.generateParenthesis(3);
    for (auto s : x ) {
        cout << s << "  ";
    }
    cout << endl;
}

