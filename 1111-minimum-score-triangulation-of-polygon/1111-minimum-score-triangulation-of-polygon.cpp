class Solution {
public:
    int dp[100][100];
    int solve(vector<int>&values,int i,int j)
    {
        //base case-->
        if(j-i+1<3)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
          return dp[i][j];
        
        int mini=INT_MAX;
       // int ans=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
             int ans=values[i]*values[j]*values[k]+solve(values,i,k)+solve(values,k,j);
             mini=min(mini,ans);
        }

        //return ans;
        return dp[i][j]=mini;
    }
    int minScoreTriangulation(vector<int>& values) {
       
       int i=0;
       int j=values.size()-1;
   
       memset(dp,-1,sizeof(dp));

       return solve(values,i,j);
        
    }
};