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
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& pre, vector<int>& in, int preStart, int inStart, int inEnd)
    {
        // if we are out of bounds, return
        if (inStart > inEnd) return NULL;
        
        // make our new root node
        TreeNode* root = new TreeNode(pre[preStart]);
        
        // find where our current root is in the inorder.
        int rootIdx = 0;
        while (pre[preStart] != in[rootIdx]) rootIdx++;
        
        // left goes until we find the node in inorder
        root->left = build(pre, in, preStart + 1, inStart, rootIdx-1);
        // right goes from the node in inorder, to the end.
        root->right = build(pre, in, preStart + (rootIdx - inStart + 1), rootIdx + 1, inEnd); 
        
        return root;
    }
};