class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) 
    {
       vector<vector<int>> ans;
        sort(in.begin(),in.end());
        for(int i=0;i<in.size();i++)
        {
            vector<int>temp=in[i];
            while(i<in.size()-1 && temp[1]>=in[i+1][0])
            {
                temp[1]=max(temp[1],in[i+1][1]);
                i++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};