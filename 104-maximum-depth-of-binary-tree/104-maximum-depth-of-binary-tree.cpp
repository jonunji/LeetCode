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
    int maxDepth(TreeNode* root) 
    {
        int max = 0;
        
        maxDepthHelper(root, 0, max);
        
        return max;
    }
    
    void maxDepthHelper(TreeNode* root, int curr, int &max)
    {
        if (root == NULL)
        {
            if (curr > max) max = curr;
            
            return;
        }
        maxDepthHelper(root->left, curr+1, max);
        maxDepthHelper(root->right, curr+1, max);
    }
};