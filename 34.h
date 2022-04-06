#include"head.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root) return {};
        vector<vector<int>> r;
        vector<int> temp;
        dfs(root, target, temp, r);
        return r;
    }
    void dfs(TreeNode* root, int target, vector<int>& r,vector<vector<int>>&res)
    {
        if(!root) return;
        r.push_back(root -> val);
        if(!root -> left && !root -> right && target == root -> val)
        {
            res.push_back(r);
        }
        dfs(root -> left, target - root -> val, r,res);
        dfs(root -> right, target - root -> val, r,res);
        r.pop_back();  
    }
};