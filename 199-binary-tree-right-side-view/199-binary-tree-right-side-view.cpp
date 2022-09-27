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
        
        q.push(root);
        q.push(NULL);
        while (q.front())
        {
            TreeNode* curr;
            while (q.front())
            {
                curr = q.front();
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                
                q.pop();
            }
            // get rid of the NULL
            q.pop();
            q.push(NULL);
            
            right.push_back(curr->val);
        }
        
        return right;
    }
};