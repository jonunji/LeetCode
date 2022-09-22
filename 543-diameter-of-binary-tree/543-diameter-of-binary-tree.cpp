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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int max = 0;
        
        findMax(root, max);
        
        return max;
    }
    
    int findMax(TreeNode* root, int& maxLen)
    {
        if (!root) return 0;
        
        int left = findMax(root->left, maxLen);
        int right = findMax(root->right, maxLen);
        
        maxLen = max(left + right, maxLen);
        
        return max(left, right) + 1;
    }
};