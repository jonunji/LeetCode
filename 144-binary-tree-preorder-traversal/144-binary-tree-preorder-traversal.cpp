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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> s;
        vector<int> res;
        
        while (!s.empty() || root)
        {
            if (root)
            {
                s.push(root);
                res.push_back(root->val);
                root = root->left;
            }
            else
            {
                root = s.top()->right;
                s.pop();
            }
        }
        
        return res;
    }
};