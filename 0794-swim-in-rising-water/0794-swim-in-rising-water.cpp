class Solution {
public:
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int val,vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis)
    {
        vis[i][j]=true;

        for(auto &dir:directions)
        {
            int x=i+dir[0];

            int y=j+dir[1];

            if(x>=0 && y>=0 && x<grid.size() && y<grid.size() && grid[x][y]<=val && !vis[x][y])
            {
                 dfs(val,grid,x,y,vis);
            }
        }
       
       return;

    }
    int swimInWater(vector<vector<int>>& grid) {

        int start=grid[0][0];

        int end=INT_MIN;

        int row=grid.size();

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<row;j++)
            {
               end=max(grid[i][j],end);
            }
        }

        int ans=0;

        while(start<=end)
        {
            int mid=(start+end)/2;

            vector<vector<bool>>vis(row,vector<bool>(row,false));

            dfs(mid,grid,0,0,vis);

            if(vis[row-1][row-1])
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }

        return ans;

    }
};