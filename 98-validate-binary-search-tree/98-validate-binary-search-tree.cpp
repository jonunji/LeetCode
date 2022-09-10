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
    bool isValidBST(TreeNode* root) 
    {
        return check(root->right, root->val, INT_MAX, 1) 
            && check(root->left, INT_MIN, root->val, 2);
    }
    
    bool check(TreeNode* root, int low, int high, int mask)
    {
        if (root == NULL)
            return true;
        
        if ((1 & mask && root->val <= low) || (1 & (mask >> 1) && root->val >= high))
            return false;
        
        return check(root->right, max(low, root->val), high, root->val > low ? mask|1 : mask) // check right
            && check(root->left, low, min(high, root->val), root->val < high ? mask|2 : mask); // check left
    }
};