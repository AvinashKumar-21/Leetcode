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
    vector<string>ans;
    bool check(TreeNode*root)
    {
        if(!root->left&& !root->right)
            return true;
        return false;
    }
    void fun(TreeNode*root,string s)
    {
        if(!root)
            return;
        s.append(to_string(root->val)+"->");
        if(check(root))
        {
            for(int i=0;i<2;i++)
            s.pop_back();
            ans.push_back(s);
        }
        fun(root->left,s);
        fun(root->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(!root)
            return ans;
        fun(root,"");
        return ans;
    }
};