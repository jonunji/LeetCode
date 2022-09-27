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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> right;
        queue<TreeNode*> q;
        
        if (root == NULL) return right;
        
        q.push(root);
        while (!q.empty())
        {
            TreeNode* curr;
            
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                curr = q.front();
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                
                q.pop();
            }
            
            right.push_back(curr->val);
        }
        
        return right;
    }
};