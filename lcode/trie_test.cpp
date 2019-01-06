/*
 * =====================================================================================
 *
 *       Filename:  trie_test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/11/2018 04:18:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

// string::empty
#include <iostream>
#include <string>
using namespace std;
#define N 26
class Trie {
public:
    /** Initialize your data structure here. */
    Trie *children[N];
    bool _isWord;
    
    Trie() {
        
        _isWord = false;
        for ( int i=0; i < N; i++)
            children[i] = NULL;
    }
    void setWord(void) {
        _isWord = true;
    }
    bool isWord(void) {
        return _isWord;
    }
    
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *cur = this;
        for (uint i=0;i < word.length();i++) {
            
            int idx = word[i] - 'a';
            cout << " adding " << word[i];
            if (cur->children[idx] == NULL) {
                /* add node with the char */
                cur->children[idx] = new Trie();
                
            }
            cur = children[idx];
        }
        cur->setWord();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *cur = this;
        for (uint i=0;i < word.length();i++) {
            cout << " adding " << word[i];
            int idx = word[i] - 'a';
            if (cur->children[idx] == NULL) return false;
        }
        if (cur->isWord()) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *cur = this;
        for (uint i=0;i < prefix.length();i++) {
            int idx = prefix[i] - 'a';
            if (cur->children[idx] == NULL) return false;
        }
        return true;
    }
        
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main ()
{
 string word = "apple";
 string prefix = "ap";
 Trie obj;
 obj.insert(word);
 //bool param_2 = obj.search(word);
 //bool param_3 = obj.startsWith(prefix);
 return 0;
}
