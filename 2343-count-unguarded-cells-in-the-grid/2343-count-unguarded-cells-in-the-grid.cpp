class Solution {
public:
    void mark(int i,int j, vector<vector<int>>&t)
    {
        int left=j-1;

        int row=t.size();

        int col=t[0].size();

         while(left>=0 && t[i][left] != 2 && t[i][left] != 1)
         {
            t[i][left]=0;
            left--;
         }

         int right= j+1;

         while(right<col && t[i][right] != 2 && t[i][right] != 1)
         {
            t[i][right]=0;
            right++;
         }

         int up=i-1;

         while(up>=0 && t[up][j] != 2 && t[up][j] != 1)
         {
            t[up][j]=0;
            up--;
         }

         int down=i+1;
         
          while(down<row && t[down][j] != 2 && t[down][j] != 1)
         {
            t[down][j]=0;
            down++;
         }


    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        

        int g=1;
        int w=2;

        int size=m*n;
        int gSize=guards.size();
        int wSize=walls.size();

        vector<vector<int>>t(m,vector<int>(n,-1));

        for(auto val: guards)
        {
            int i=val[0];
            int j=val[1];

            t[i][j]=g;
        }
        for(auto val: walls)
        {
            int i=val[0];
            int j=val[1];

            t[i][j]=w;
        }
        


        for(auto val:guards)
        {
            int i=val[0];
            int j=val[1];

            mark(i,j,t);
        }

        int count=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(t[i][j]==-1)
                {
                    count++;
                }
            }
        }
          
       return count;

    }
};