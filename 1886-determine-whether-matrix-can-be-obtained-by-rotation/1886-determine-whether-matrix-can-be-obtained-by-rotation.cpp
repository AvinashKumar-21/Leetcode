class Solution {
public:
    bool findRotation(vector<vector<int>>& m, vector<vector<int>>& t) 
    {
        bool ans[4];
        bool flag[4];
        memset(flag,true,sizeof(flag));
        memset(ans,true,sizeof(ans));
        int n=m.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(m[i][j]!=t[i][j] && flag[0])
                    ans[0]=false;
                if(m[i][j]!=t[j][n-1-i] && flag[1])
                    ans[1]=false;
                if(m[i][j]!=t[n-1-i][n-1-j] && flag[2])
                    ans[2]=false;
                if(m[i][j]!=t[n-j-1][i] && flag[3])
                    ans[3]=false;
            }
        }
        return ans[0]||ans[1]||ans[2]||ans[3];
    }
};