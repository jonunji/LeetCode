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
    int count = 0;
    
    int goodNodes(TreeNode* root) 
    {
        countGood(root, root->val);
        
        return count;
    }
    
    void countGood(TreeNode* root, int currMax)
    {
        if (root == NULL) return;
        
        if (root->val >= currMax)
        {
            currMax = root->val;
            count++;
        } 
        
        countGood(root->left, currMax);
        countGood(root->right, currMax); 
    }
};