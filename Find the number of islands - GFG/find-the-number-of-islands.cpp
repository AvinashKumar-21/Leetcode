//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<vector<int>>v;
    void fun(int i,int j,vector<vector<char>>grid)
    {
        v[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop();
            for(int a=-1;a<=1;a++)
        {
            for(int b=-1;b<=1;b++)
            {
                int r=i-a;
                int c=j-b;
                if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]=='1' && v[r][c]==0)
                {
                    q.push({r,c});
                    v[r][c]=1;
                }
            }
        }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        v.resize(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && v[i][j]==0)
                {
                    fun(i,j,grid);
                ans++;
                }
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends