#include"head.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> r;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* t = q.front();
            r.push_back(t -> val);
            q.pop();
            if(t -> left) q.push(t -> left);
            if(t -> right) q.push(t -> right);
        }
        return r;
    }
};