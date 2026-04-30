class Solution {
public:

    int m,n;

    int minOperations(vector<vector<int>>& grid, int x) {
        
       m=grid.size();
       n=grid[0].size();

       vector<int>val;

       for(int i=0;i<m;i++)
       {
          for(int j=0;j<n;j++)
          {
             val.push_back(grid[i][j]);
          }
       }

       sort(val.begin(),val.end());

       int mini = 0;

       int median = (val.size())/2;

       int num=val[median];

       for(int i=0;i<val.size();i++)
       {
          if(abs(num-val[i])%x!=0) return -1;
          if(i!=median)
          {
             mini+=(abs(num-val[i])/x);
          }
       }

      return mini;
        
    }
};