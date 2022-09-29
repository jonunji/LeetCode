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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int root = 0;
        return build(preorder, inorder, root, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& pre, vector<int>& in, int& root, int inStart, int inEnd)
    {
        // if we are out of bounds, return
        if (inStart > inEnd) return NULL;
        
        // make our new root node
        TreeNode* curr = new TreeNode(pre[root]);
        
        // find where our current root is in the inorder.
        int pivot = 0;
        while (pre[root] != in[pivot]) pivot++;
        
        root++;
        
        // left goes until we find the node in inorder
        curr->left = build(pre, in, root, inStart, pivot-1);
        // right goes from the node in inorder, to the end.
        curr->right = build(pre, in, root, pivot + 1, inEnd); 
        
        return curr;
    }
};