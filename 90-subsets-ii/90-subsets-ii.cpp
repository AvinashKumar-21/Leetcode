class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        set<vector<int>>s;
        for(int i=0;i<(1<<nums.size());i++)
        {
            vector<int>a;
            for(int j=0;j<nums.size();j++)
                if(i & (1<<j))
                    a.push_back(nums[j]);
            sort(a.begin(),a.end());
            s.insert(a);
        }
        for(auto i:s)
            ans.push_back(i);
        return ans;
    }
};