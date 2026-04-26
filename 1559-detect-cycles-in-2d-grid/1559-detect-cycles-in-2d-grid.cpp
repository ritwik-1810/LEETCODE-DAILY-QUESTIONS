class Solution {
public:
    vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(vector<vector<char>>& grid,int i,int j ,int parenti,int parentj,vector<vector<bool>>&vis)
    {
         vis[i][j]=true;

         for(auto d:dir)
         {
             int nx=i+d[0];

             int ny=j+d[1];

             if(nx==parenti && ny==parentj)
             {
                 continue;
             }

             if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[i][j]==grid[nx][ny])
             {
                if(vis[nx][ny])
                {
                    return true;
                }
                
                if(dfs(grid,nx,ny,i,j,vis)){
                    return true;
                }
                
             }
         }

         return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {

        int row = grid.size();

        int col = grid[0].size();

        vector<vector<bool>>vis(row,vector<bool>(col));

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                 if(!vis[i][j])
                 {
                     if(dfs(grid,i,j,-1,-1,vis))
                     {
                        return true;
                     }
                 }
            }
        }

        return false;
        
    }
};