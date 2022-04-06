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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, int(preorder.size()) - 1, 0, int(inorder.size()) - 1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preBegin, int preEnd, int inBegin, int inEnd) {
        if(inBegin > inEnd or preBegin > preEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preBegin]);
        int t;
        for(int i = inBegin; i < inEnd; i++)
        {
            if(inorder[i] == preorder[preBegin])
            {
                t = i; 
                break;
            }
        }
        int leftNum = t - inBegin; 
        int rightNum = inEnd - t;
        root -> left = build(preorder, inorder, preBegin + 1, preBegin + leftNum, t - leftNum, t - 1);
        root -> right = build(preorder, inorder, preBegin + leftNum + 1, preBegin + leftNum + rightNum, t + 1, t + rightNum);
        return root;
    }  
};