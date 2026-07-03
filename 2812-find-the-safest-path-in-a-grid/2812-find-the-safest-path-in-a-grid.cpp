class Solution {
public:
    vector<vector<int>>d{{0,1},{0,-1},{-1,0},{1,0}};

    bool bfs(vector<vector<int>>& dir,int mid)
    {
        queue<pair<int,int>>q;

        int row=dir.size();

        if(dir[0][0]<mid) return false;

        q.push({0,0});

        vector<vector<bool>>vis(row,vector<bool>(row,false));

        vis[0][0] = true;

         while(!q.empty())
        {
           auto [i,j] = q.front();

           if(i==row-1 && j==row-1) return true;

           q.pop();

           for(auto &dd:d)
           {
               int ni=dd[0]+i;

               int nj=dd[1]+j;

               if(ni>=0 && ni<row && nj>=0 && nj<row && !vis[ni][nj] && dir[ni][nj]>=mid)
               {
                 vis[ni][nj]=true;
                 q.push({ni,nj});
               }
           }
        }

        return false;

    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {


        int row = grid.size();

        int col=row;

        queue<pair<int,int>>q;

        vector<vector<int>>dis(row,vector<int>(row,INT_MAX));

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<row;j++)
            {
                if(grid[i][j]==1)
                {
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty())
        {
           auto [i,j] = q.front();

           q.pop();

           for(auto dd:d)
           {
               int ni=dd[0]+i;

               int nj=dd[1]+j;

               if(ni>=0 && ni<row && nj>=0 && nj<row && dis[ni][nj]==INT_MAX)
               {
                 dis[ni][nj]=dis[i][j]+1;
                 q.push({ni,nj});
               }
           }
        }

        int start = 0; 

        int end = 2 * row;

        int ans=0;

        while(start<=end)
        {
           int mid =   start + (end-start) /2;

           if(bfs(dis,mid))
           {
              ans=mid;

              start=mid+1;
           }
           else
           {
              end=mid-1;
           }
        }

        return ans;

    }
};