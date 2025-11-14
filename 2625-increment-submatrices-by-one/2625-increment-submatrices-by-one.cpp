class Solution {
public:
    void difference_array(vector<vector<int>>&ans,int start_i,int start_j,int end_i,int end_j,int n)
    {

         for(int i=start_i;i<=end_i;i++)
         {
            ans[i][start_j]+=1;
         }

         if(end_j+1<n)
         {
            for(int i=start_i;i<=end_i;i++)
            {
                ans[i][end_j+1]-=1;
            }  
         }
         
    }
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>>ans(n,vector<int>(n,0));

        for(auto v:queries)
        {
            int start_i=v[0];

            int start_j=v[1];

            int end_i=v[2];

            int end_j=v[3];

            difference_array(ans,start_i,start_j,end_i,end_j,n);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                ans[i][j]+=ans[i][j-1];
            }
        }

        return ans;
        
    }
};