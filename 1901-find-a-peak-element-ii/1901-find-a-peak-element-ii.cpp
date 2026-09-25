class Solution {
public:
     int findMaximum(int col,vector<vector<int>>& mat)
    {
        int maximumIdx=-1;

        int maximum=0;

        for(int i=0;i<mat.size();i++)
        {
            if(maximum<mat[i][col])
            {
                maximum=mat[i][col];

                maximumIdx=i;
            }
        }

        return maximumIdx;

    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        //brute force approach-->

         int row=mat.size();

        int col=mat[0].size();

        int start=0;

        int end=col-1;

        int mid=-1;

        while(start<=end)
        {
           mid=(start + end)/2;

           int row_num=findMaximum(mid,mat);

           if(mid-1>=0 && mid+1<col)
           {
               if(mat[row_num][mid+1]<mat[row_num][mid] && mat[row_num][mid-1]<mat[row_num][mid])
                return {row_num,mid};
               
               if(mat[row_num][mid-1]>mat[row_num][mid])
                 end=mid-1;
               else
                 start=mid+1;
           }
           else if(mid==start && mid==end)
           {
                return {row_num,mid};
           }
           else if(mid-1==-1)
           {
              if(mat[row_num][mid+1]<mat[row_num][mid])
                return {row_num,mid};
              start=mid+1;
           }
           else if(mid+1==col)
           {
              if(mat[row_num][mid-1]<mat[row_num][mid])
                return {row_num,mid};
              end=mid-1;
           }
        }

        return {-1,-1};
        
          
        
    }
};