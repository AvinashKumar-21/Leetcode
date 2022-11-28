class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) 
    {
        int n=t.size()-1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<t[i].size();j++)
                t[i][j]+=min(t[i+1][j],t[i+1][j+1]);
        }
        return t[0][0];
    }
};