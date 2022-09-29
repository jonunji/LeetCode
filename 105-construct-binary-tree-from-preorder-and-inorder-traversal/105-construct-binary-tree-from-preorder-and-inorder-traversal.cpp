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
        if (preStart >= pre.size() || inStart > inEnd) return NULL;
        
        TreeNode* curr = new TreeNode(pre[preStart]);
        int rootIdx = 0;
        while (pre[preStart] != in[rootIdx]) rootIdx++;
        
        curr->left = build(pre, in, preStart + 1, inStart, rootIdx-1);
        curr->right = build(pre, in, preStart + (rootIdx - inStart + 1), rootIdx + 1, inEnd); 
        
        return curr;
    }
};