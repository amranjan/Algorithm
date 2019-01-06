/*
 * =====================================================================================
 *
 *       Filename:  autocomplete.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/14/2018 12:31:38 AM
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
#include <map>
#include <set>
#include <vector>

using namespace std;


struct TrieNode {
    int hotness;
    map <char, TrieNode *> next;
    TrieNode () {
        hotness = 0;
    }
};
    struct sentence_node {
        string s;
        int value;
        sentence_node(int _val, string _s) : value(_val), s(_s) { }
        
    };
    bool operator<(const sentence_node& lhs, const sentence_node& rhs)
    {
      if (lhs.value == rhs.value) return true;
      return lhs.value > rhs.value;
    }
    
class AutocompleteSystem {
    TrieNode *root;
    string cur_input;
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        /* add all sentences */
        auto it = times.begin();
        for (auto sen : sentences) {
            insert(sen , *it);
            it++;
        }
    }
    void insert(string sentence, int times)  {
        //cout << "inserting "<< sentence << " times " << times << endl;
        TrieNode *p = root;
        for (auto c : sentence) {
            if (p->next.count(c) <=0) {
                p->next[c] = new TrieNode();
            }
            p = p->next[c];
        }
        p->hotness += times;
    }
    

    void get_sen_list(TrieNode *p, string &prefix, string cur_sentence, set<sentence_node> &s_list) {
        //cout << "sentence is " << cur_sentence << endl;

        if (p->hotness >0 ) {
            /* It means this is one sentence */
            struct sentence_node _s(p->hotness,prefix+cur_sentence);
            s_list.insert(_s);
        }
        /* now look further for other sentences in the childrent list */
        for (auto it = p->next.begin(); it != p->next.end(); it++) {
            string next_sentence(cur_sentence);
            next_sentence.push_back(it->first);
            get_sen_list(it->second, prefix, next_sentence, s_list);
        }
    }
    vector<string> input(char c) {
        
        vector <string> _list;
        set <sentence_node> sen_list;
        string prefix(cur_input);
        if (c == '#') {
            insert(cur_input, 1);
            cur_input.clear();
            return _list;
        } else {
            cur_input.push_back(c);
        }
        /*  find the cur_input `in the Trie before looking list of sentences   */

        TrieNode *p = root;
        for (auto c : cur_input) {
            if (p->next.count(c) <= 0) {
                p = NULL;
                break; 
            }
            p = p->next[c];
        }
        if (p == NULL) {
            /*  sentence does not exists with the input. return empty list */
            return _list;
        }
        /*  Now look for all possible sentences existing in the data structure  */
        string cur_sentence;
        cur_sentence.push_back(c);
        get_sen_list(p, prefix, cur_sentence, sen_list);
        /* now we got the list of all sentences with a character */
        int count = 0, prev_times ;
        for (auto it = sen_list.begin(); it != sen_list.end(); it++ ) {
            if ((count == 3) && (it->value < prev_times)) {
                /*  done here just return */
                continue;
            }
            if ((count == 3) && (it->value == prev_times)) {
                /*  Here already 3 sentences are selected and times is same 
                 *  as previous sentence then compare the sentence itself and 
                 *  choose the lower one */
                string _prev_sen = _list.back();
                if (_prev_sen > it->s) {
                    _list.pop_back();
                    count--;
                }
            }

            _list.push_back(it->s);
            count++;
            prev_times = it->value;
            //cout << it->s << endl;
        }
        return _list;
    }
};


int main(void) {

    vector <string> sentences = { "i love you","island","ironman","i love leetcode"};
    vector <int > times = {5,3,2,7};
    AutocompleteSystem *obj = new AutocompleteSystem(sentences, times);
    char c = 'i';
    cout << " checking for i\n" ;
    vector<string> p = obj->input(c);
    for (auto sen : p) {
        cout << sen <<endl;
    }
    vector<string> p1 = obj->input(' ');
    for (auto sen : p1) {
        cout << sen <<endl;
    }
}
