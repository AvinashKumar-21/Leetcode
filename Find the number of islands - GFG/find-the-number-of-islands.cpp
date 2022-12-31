//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<vector<int>>visited;
    void fun(int i,int j,vector<vector<char>>grid)
    {
        visited[i][j]=1;
        queue<pair<int,int>>st;
        int n=grid.size();
        int m=grid[0].size();
        st.push({i,j});
        while(!st.empty())
        {
            i=st.front().first;
            j=st.front().second;
            st.pop();
            for(int minRow=-1;minRow<=1;minRow++)
            {
                for(int minCol=-1;minCol<=1;minCol++)
                {
                    int reqR=i-minRow;
                    int reqC=j-minCol;
                    if(reqR>=0 && reqR<n && reqC>=0 && reqC<m && grid[reqR][reqC]=='1' && visited[reqR][reqC]==0)
                    {
                        visited[reqR][reqC]=1;
                        st.push({reqR,reqC});
                    }
                }
            }
            
        }

    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int ans=0;
        visited.resize(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
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