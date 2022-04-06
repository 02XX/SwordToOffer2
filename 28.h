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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isSame(root -> left, root -> right);
    }
    bool isSame(TreeNode* L, TreeNode* R)
    {
        if(L == nullptr && R == nullptr) return true;
        if(L == nullptr || R == nullptr || L -> val != R -> val) return false;
        return isSame(L->left, R->right) && isSame(L -> right, R->left);
    }
};

