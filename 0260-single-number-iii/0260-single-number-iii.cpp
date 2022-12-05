class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        map<int,int>m;
        vector<int>ans;
        for(auto i:nums)
        {
            if(m.find(i)!=m.end())
                m[i]++;
            else
                m[i]=1;
        }
        for(auto i:m)
            if(i.second==1)
                ans.push_back(i.first);
        return ans;        
    }
};