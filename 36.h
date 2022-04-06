#include"head.h"
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
Node* pre = nullptr;
Node* begin = nullptr;
Node* treeToDoublyList(Node* root) {
        if(!root) return begin;
        inOrder(root);
        begin -> left = pre;
        pre -> right = begin;
        return begin;
    }
    void inOrder(Node* root) {
        if(root)
        {
            inOrder(root -> left);
            if(!pre) begin = root;
            else
                pre -> right = root;
            root -> left = pre;
            pre = root;
            inOrder(root -> right);
        }
    }
};