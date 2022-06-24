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
    vector<vector<int>>ans;
    bool check(TreeNode*root)
    {
        if(!root->left && !root->right)
            return true;
        return false;
    }
    void fun(TreeNode*root,int sum,vector<int>a)
    {
        if(!root)
            return ;
        a.push_back(root->val);
        if(check(root) && sum==root->val)
            ans.push_back(a);
        fun(root->left,sum-root->val,a);
        fun(root->right,sum-root->val,a);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) 
    {
        
        if(!root)
            return ans;
        vector<int>a;
        fun(root,t,a);
        return ans;
    }
};