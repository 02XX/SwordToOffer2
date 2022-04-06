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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* nothing = new TreeNode(1001);
        while(!q.empty())
        {
            TreeNode * t = q.front();
            if(t -> val != 1001)
            {
                if(t -> val >= 0)
                    res += ( "{+" + to_string(q.front() -> val) + "}");
                else
                    res += ("{" + to_string(q.front() -> val) + "}");
                q.pop();
            }
            else
            {
                res += "{+#}";
                q.pop();
                continue;
            }
            if(t -> left)
                q.push(t -> left);
            else
                q.push(nothing);
            if(t -> right)
                q.push(t -> right);
            else
                q.push(nothing);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;

        vector<string> deString;
        int valBegin = 0, valEnd = 0;
        int dataSize = static_cast<int>(data.size());
        while(valBegin < dataSize)
        {
            string num;
            if(data[valBegin] == '{')
            {
                while(data[valEnd] != '}') valEnd++;
            }
            num = data.substr(valBegin + 1, valEnd - valBegin - 1);
            deString.push_back(num);
            valBegin = valEnd + 1;
            valEnd = valBegin;
        }

        //initialization
        string num = deString[0];
        TreeNode* res = new TreeNode(stoi(num));       
        queue<TreeNode*> q;
        q.push(res);
        for(size_t i = 1; i < deString.size(); i += 2)
        {
            string numLeft = deString[i];
            string numRight = deString[i + 1];
            TreeNode* tempLeft = nullptr, *tempRight = nullptr;
            if(numLeft == "+#") 
                tempLeft = nullptr;
            else
                tempLeft = new TreeNode(stoi(numLeft)); 
            
            if(numRight == "+#") 
                tempRight = nullptr;
            else
                tempRight = new TreeNode(stoi(numRight)); 

            if(tempLeft) q.push(tempLeft);
            if(tempRight) q.push(tempRight);
            if(q.front())
            {
                q.front() -> left = tempLeft;
                q.front() -> right = tempRight;
                q.pop();
            }
        }
        return res;  
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));