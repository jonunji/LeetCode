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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> currPath;
        vector<vector<int>> result;
        
        pathSumHelper(root, targetSum, result, currPath); 
        
        return result;
    }
    
    void pathSumHelper(TreeNode* root, int targetSum, vector<vector<int>> &result, vector<int> &currPath)
    {
        if (root == NULL)
            return;
            
        currPath.push_back(root->val);    
        if (!(root->left) && !(root->right) && root->val == targetSum)
            result.push_back(currPath);
         
        pathSumHelper(root->left, targetSum - root->val, result, currPath);
        pathSumHelper(root->right, targetSum - root->val, result, currPath);
        
        currPath.pop_back();
    }
};