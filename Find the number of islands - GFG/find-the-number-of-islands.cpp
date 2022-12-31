//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<vector<bool>>v;
    void fun(int i,int j,vector<vector<char>>& grid)
    {
        v[i][j]=true;
        int n=grid.size();
        int m=grid[0].size();
        for(int a=-1;a<=1;a++)
        {
            for(int b=-1;b<=1;b++)
            {
                int newRow=i-a;
                int newCol=j-b;
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !v[newRow][newCol] && grid[newRow][newCol]=='1')
                fun(newRow,newCol,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        v.resize(grid.size(),vector<bool>(grid[0].size(),false));
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(!v[i][j] && grid[i][j]=='1')
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