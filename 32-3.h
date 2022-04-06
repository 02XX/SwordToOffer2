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
        bool flag = true;
        while(!q.empty())
        {
            vector<int> temp;
            int s = q.size();
            stack<int> ss;
            for(int i = 0; i < s; i++)
            {
                if(flag)
                    temp.push_back(q.front() -> val);
                else
                {
                    ss.push(q.front() -> val);
                }
                if(q.front() -> left) q.push(q.front() -> left);
                if(q.front() -> right) q.push(q.front() -> right);
                q.pop();
            }
            
            while(!ss.empty())
            {
                temp.push_back(ss.top());
                ss.pop();
            }
            
            flag = !flag;
            r.push_back(temp); 
        }
        return r;
    }
};