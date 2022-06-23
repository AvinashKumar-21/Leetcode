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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int>ans;
        if(!root)
        return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        map<int,int>s;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                root=q.front().first;
                int temp=q.front().second;
                q.pop();
                s[temp]=root->val;
                if(root->left)
                q.push({root->left,temp+1});
                if(root->right)
                q.push({root->right,temp+1});
            }
        }
        for(auto i:s)
        ans.push_back(i.second);
        return ans;
    }
};