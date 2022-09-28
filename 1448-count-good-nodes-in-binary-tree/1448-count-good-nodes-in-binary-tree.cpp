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
    int goodNodes(TreeNode* root) 
    {
        int count = 0;
        countGood(root, root->val, count);
        
        return count;
    }
    
    void countGood(TreeNode* root, int currMax, int& count)
    {
        if (root == NULL) return;
        
        if (root->val >= currMax)
        {
            currMax = root->val;
            count++;
        }
        
        countGood(root->left, currMax, count);
        countGood(root->right, currMax, count);
    }
};