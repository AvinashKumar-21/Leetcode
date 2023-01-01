//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

vector<vector<bool>>v;
void fun(int i,int j,vector<vector<int>>& image,int color,int curr)
{
    v[i][j]=false;
    image[i][j]=color;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty())
    {
        i=q.front().first;
        j=q.front().second;
        q.pop();
        if(i-1>=0 && image[i-1][j]==curr && v[i-1][j])
        {
            v[i-1][j]=false;
            image[i-1][j]=color;
            q.push({i-1,j});
        }
        if(i+1<image.size() && image[i+1][j]==curr && v[i+1][j])
        {
            v[i+1][j]=false;
            image[i+1][j]=color;
            q.push({i+1,j});
        }
        if(j-1>=0 && image[i][j-1]==curr && v[i][j-1])
        {
            v[i][j-1]=false;
            image[i][j-1]=color;
            q.push({i,j-1});
        }
        if(j+1<image[0].size() && image[i][j+1]==curr && v[i][j+1])
        {
            v[i][j+1]=false;
            image[i][j+1]=color;
            q.push({i,j+1});
        }
    }
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        v.resize(image.size(),vector<bool>(image[0].size(),true));
        fun(sr,sc,image,newColor,image[sr][sc]);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends