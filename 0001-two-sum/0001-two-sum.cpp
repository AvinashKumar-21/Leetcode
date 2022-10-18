class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) 
    {
        map<int,int>s;
        for(int i=0;i<n.size();i++)
        {
            if(s.find(t-n[i])!=s.end())
            {
                return {s[t-n[i]],i};
            }
            else
            {
                s[n[i]]=i;
            }
        }
        return {};
    }
};