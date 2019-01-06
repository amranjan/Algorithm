/*
 * =====================================================================================
 *
 *       Filename:  kthLargest.cpp
 *
 *    Description:  Kth Largest num from a unsorted list
 *
 *        Version:  1.0
 *        Created:  11/18/2018 01:51:56 AM
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
struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
    treeNode(int value) : val(value), left(NULL), right(NULL) {}
};
class Solution {
    struct treeNode *root;
    int k_offset  =0;
    
    void add(int value) {
        struct treeNode *temp = new treeNode(value);
        struct treeNode *cur = root, *prev = NULL;
        if (root == NULL)  {root = temp; }
        else  {
            while (cur != NULL) {
                prev = cur;
                if (value < cur->val) cur = cur->left;
                else  cur = cur->right;
            }
            if (value < prev->val) prev->left = temp;
            else prev->right = temp;
        }
    }
    struct treeNode *getKthLargest(struct treeNode *node, int &cur_offset){
        if (node == NULL) return NULL;
        struct treeNode *temp = NULL;
        if (node->right) {
            temp = getKthLargest(node->right, cur_offset);
            if (cur_offset == k_offset) return temp;
        }
        cur_offset++;
        if (cur_offset == k_offset) return node;
        if (node->left) return getKthLargest(node->left, cur_offset);
        return NULL;
    }
public:
    Solution() {root = NULL;}
    
    int findKthLargest(vector<int>& nums, int k) {
        // k_offset = nums.size() - k +1;
         k_offset = k ;
        
        for (int idx = 0; idx < nums.size(); idx++) {
            cout << " Add " << nums[idx] << endl;
            add(nums[idx]);
        }
        int cur_offset =0; 
        struct treeNode *node = getKthLargest(root, cur_offset);
        if (node) return node->val;
        return 0;
    }
};

int main ()
{
    Solution obj;
    vector <int> n = {3,2,1,5,6,4};
    int k = 2;
    cout << " find kth largest " << endl;
    cout << obj.findKthLargest(n, k) << endl;
 
}
