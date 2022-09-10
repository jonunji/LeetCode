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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> s;    
        vector<int> res;
    
        while (!s.empty() || root != NULL)
        {
            if (root)
            {
                s.push(root);
                res.push_back(root->val);
                root = root->right;
            }
            else
            {
                root = s.top()->left;
                s.pop(); 
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    
    
    
//     recursive
//     =============
//     vector<int> postorderTraversal(TreeNode* root) 
//     {
//         if (root == NULL) return {};
        
//         vector<int> res;
        
//         post(root, res);
//         return res;
//     }
    
//     void post(TreeNode* root, vector<int>& res)
//     {
//         if (root == NULL) return;
        
//         post(root->left, res);
//         post(root->right, res);
        
//         res.push_back(root->val);
//     }
};