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
#include <queue>

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

typedef struct StackNode {
    void *val;
    StackNode *next;
    StackNode(void *ptr) : val(ptr), next(NULL) {}
} StackNode;

bool push_node (StackNode **top, void *val) {
    auto temp = new StackNode(val);
    if (temp == NULL) return false;
    temp->next = *top;
    *top = temp;
    return true;
}

bool pop_node(StackNode **top, void **val) {
    if ((top == NULL) || (*top == NULL)) return false;
    auto temp = *top;
    *val = temp->val;
    *top = temp->next;
    free(temp);
    return true;
}

void inorder_traversal(BtreeNode *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        cout << root->val << " ";
        inorder_traversal(root->right);
    }
}

void preorder_traversal(BtreeNode *root) {
    if ( root == NULL)   return ;
    StackNode *top = NULL;
    BtreeNode *cur = root;

    do {
        cout << cur->val << " ";
        if ( cur->left != NULL) {
            push_node(&top, (void *)cur);
            cur = cur->left;
        } else if (cur->right != NULL) {
            cur = cur->right;
        } else{
            /*  Get the right node of the the pushed node */
            BtreeNode *temp = NULL;
            cur = NULL;
            while (top != NULL)  {
                pop_node(&top, (void **) &temp);
                if (temp->right != NULL) {
                    cur = temp->right;
                }
            }
            if (cur == NULL) {
                /*  nothing to process  return */
                return ;

            }
        }
    } while (1);
}

void postorder_traversal(BtreeNode *root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->val << " ";
    }
}


typedef struct QueueNode {
    BtreeNode *node;
    int level;
    QueueNode(BtreeNode *n, int l) : node(n), level(l){}
} QueueNode;

#define MAX_LEVEL 10
vector <vector<int>> levelorder_traversal(BtreeNode *root) {

    std::queue <QueueNode> bt_queue;
    vector <vector <int>> values;
    if (root == NULL) { return values; }
    values.resize(1); // init with 10 levels


    cout << root->val << " ";
    cout << endl << "levelorder travesal functiom" << endl;
    int level=0;
    QueueNode Qnode(root, level); 
    bt_queue.push(Qnode);
    values[level].push_back(root->val);
    cout << endl << "levelorder travesal functiom wile loop" << endl;
    while(!bt_queue.empty()) {
        QueueNode qnode(bt_queue.front());
        int level = qnode.level+1; // Increase the level by 1 for children
        BtreeNode *temp = qnode.node;
        values.resize(level+1);
        bt_queue.pop();
        if (temp->left != NULL) {
            QueueNode lnode(temp->left, level); 
            bt_queue.push(lnode);
            cout << temp->left->val << " ";
            values[level].push_back(temp->left->val);
        } 
        if (temp->right != NULL) {
            QueueNode rnode(temp->right, level); 
            bt_queue.push(rnode);
            cout << temp->right->val << " ";
            values[level].push_back(temp->right->val);
        } 
    }
}
int main (void) {
    vector <int > a  = { 6,4,10,1,5,3 , 12,9,2};
    vector <int > b  = { 2,3,4,5,6 };
    auto root = CreateBtree(a);
    cout << endl << "Inorder travesal" << endl;
    inorder_traversal(root);
    cout << endl << "preorder travesal" << endl;
    preorder_traversal(root);
    cout << endl << "postorder travesal" << endl;
    postorder_traversal(root);
    cout << endl << "levelorder travesal" << endl;
    auto b_root = CreateBtree(b);
    vector <vector <int>> v;
    v = levelorder_traversal(b_root);
    cout << "print in the Breadth first " << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        for (auto jt = it->begin(); jt != it->end(); jt++) {
            cout << *jt << " ";
        }
        cout << endl;
    }
    return 1;
}
