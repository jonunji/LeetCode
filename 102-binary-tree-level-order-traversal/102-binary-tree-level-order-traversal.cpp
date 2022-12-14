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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        if (root) q.push(root);
        
        vector<vector<int>> res;
        
        while(!q.empty())
        {
            vector<int> currLevel;
            
            // use NULL as our marker to know when we switch levels
            q.push(NULL);
            
            while (q.front())
            {
                // add the current node to our list
                TreeNode* curr = q.front();
                currLevel.push_back(curr->val);
                
                // push children                 
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
                
                q.pop();
            }
            
            q.pop();
            res.push_back(currLevel);
        }
        
        return res;
    }
};