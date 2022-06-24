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
    int maxi=INT_MIN;
    int fun(TreeNode*root)
    {
        if(!root)
            return 0;
        int lh=fun(root->left);
        int rh=fun(root->right);
        maxi=max(lh+rh+root->val,maxi);
        return max(lh,rh)+root->val>0?max(lh,rh)+root->val:0;
    }
    int maxPathSum(TreeNode* root) 
    {
        if(!root)
            return 0;
        fun(root);
        return maxi;
    }
};