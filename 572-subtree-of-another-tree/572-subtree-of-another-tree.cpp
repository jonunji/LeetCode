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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        stack<TreeNode*> s;
        
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode* curr = s.top();
            
            if (curr->val == subRoot->val)
            {
                bool res = checkSame(curr, subRoot);
                if (res) return true;
            }   
            
            s.pop();
            if (curr->left) s.push(curr->left);
            if (curr->right) s.push(curr->right);
        }
        
        return false;
    }
    
    bool checkSame(TreeNode* root, TreeNode* subRoot)
    {
        if (root == NULL || subRoot == NULL) return root == subRoot;
        
        return (root->val == subRoot->val) && checkSame(root->left, subRoot->left) && checkSame(root->right, subRoot->right);
    }
};