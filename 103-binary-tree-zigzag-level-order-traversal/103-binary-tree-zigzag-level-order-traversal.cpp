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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(!root)
            return ans;
        queue<TreeNode*>q;
        bool flag=true;
        q.push(root);
        while(!q.empty())
        {
            vector<int>a;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                root=q.front();
                q.pop();
                a.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            if(!flag)
                reverse(a.begin(),a.end());
            flag=!flag;
            ans.push_back(a);
        }
        return ans;
    }
};