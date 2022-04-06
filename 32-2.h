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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> r;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int s = q.size();
            for(int i = 0; i < s; i++)
            {
                temp.push_back(q.front() -> val);
                if(q.front() -> left) q.push(q.front() -> left);
                if(q.front() -> right) q.push(q.front() -> right);
                q.pop();
            }
            r.push_back(temp);
        }
        return r;
    }
};