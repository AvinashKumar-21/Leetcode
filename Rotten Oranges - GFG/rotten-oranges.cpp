//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int ans=0;
        queue<stack<pair<int,int>>>q;
        stack<pair<int,int>>s;
        int check=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                s.push({i,j});
                if(grid[i][j]==1)
                check++;
            }
        }
        q.push(s);
        while(!q.empty())
        {
            s=q.front();
            q.pop();
            stack<pair<int,int>>st;
            while(!s.empty())
            {
                int diffR[]={-1,0,1,0};
                int diffC[]={0,1,0,-1};
                int i=s.top().first;
                int j=s.top().second;
                s.pop();
                for(int a=0;a<4;a++)
                {
                    int newR=i-diffR[a];
                    int newC=j-diffC[a];
                    if(newR>=0 && newR<grid.size() && newC>=0 && newC<grid[0].size() && grid[newR][newC]==1)
                    {
                        grid[newR][newC]=2;
                        st.push({newR,newC});
                        check--;
                    }
                }
            }
            if(st.size()!=0)
            {
                q.push(st);
                ans++;
            }
            
        }
        if(check!=0)
        return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends