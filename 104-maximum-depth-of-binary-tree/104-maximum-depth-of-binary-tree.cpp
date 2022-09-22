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
        
        findMax(root, max, 1);
        
        return max;
    }
    
    void findMax(TreeNode* root, int& max, int curr)
    {
        if (!root) return;
        
        if (curr > max)
            max = curr;
        
        findMax(root->left, max, curr+1);
        findMax(root->right, max, curr+1);
    }
};