/*
 * =====================================================================================
 *
 *       Filename:  b_tree.cpp
 *
 *    Description:  Create a binary tree and perform inorder , preorder , post order travasal, 
 *
 *
 *        Version:  1.0
 *        Created:  08/31/2018 07:00:18 PM
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

using namespace std;

typedef struct BtreeNode { 
    int val; 
     BtreeNode *left;
     BtreeNode *right;
     BtreeNode (int x) : val(x), left(NULL), right(NULL){}
} BtreeNode;


BtreeNode *insertVal(BtreeNode *root, int val) {
    auto temp = new BtreeNode (val);
    if (root == NULL) {
        return temp;
    } else if (val <= root->val) {
        /*  add in the left tree */
        if (root->left == NULL) {
            root->left = temp;
        } else {
            insertVal(root->left, val);
        }
    } else {
        /*  add in the left tree */
        if (root->right == NULL) {
            root->right = temp;
        } else {
            insertVal(root->right, val);
        }
    }
    return root;

}

/*  Create Binary tree from array   */

BtreeNode *CreateBtree(vector <int> &array) {
    /*  If small add in the left if larger then add in the right  */
    BtreeNode *root = NULL;
    for (auto val : array ) {
        root = insertVal(root, val);
    }
    return root;
}


void inorder_traversal(BtreeNode *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        cout << root->val << " ";
        inorder_traversal(root->right);
    }
}

void preorder_traversal(BtreeNode *root) {
    if (root != NULL) {
        cout << root->val << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(BtreeNode *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->val << " ";
    }
}


int main (void) {
    vector <int > a  = { 6,4,10,1,5,3 , 12,9,2};
    auto root = CreateBtree(a);
    cout << endl << "Inorder travesal" << endl;
    inorder_traversal(root);
    cout << endl << "preorder travesal" << endl;
    preorder_traversal(root);
    cout << endl << "postorder travesal" << endl;
    postorder_traversal(root);
    return 1;
}
