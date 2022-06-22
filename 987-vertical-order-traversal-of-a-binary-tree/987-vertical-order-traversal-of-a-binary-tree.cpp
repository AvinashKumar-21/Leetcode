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
    map<int,map<int,multiset<int>>>map;
    void mapping(TreeNode*root,int x,int y)
    {
        if(!root)
            return;
        map[x][y].insert(root->val);
        mapping(root->left,x-1,y+1);
        mapping(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        mapping(root,0,0);
        for(auto i:map)
        {
            vector<int>a;
            for(auto j:i.second)
                for(auto k:j.second)
                a.push_back(k);
            ans.push_back(a);
        }
        return ans;
    }
};