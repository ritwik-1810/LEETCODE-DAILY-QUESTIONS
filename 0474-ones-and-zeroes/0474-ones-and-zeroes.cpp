class Solution {
public:
    int dp[601][101][101];
    
    int solve(vector<string>&nums,int m,int n, int i)
    {
        
         if(i>=nums.size() and m>=0 and n>=0) return 0;

         if(m==0 and n==0) return 0;

         if(dp[i][m][n]!=-1) return dp[i][m][n];

         int cnt1=0;

         int cnt0=0;

         for(int j=0;j<nums[i].size();j++)
         {
            if(nums[i][j]=='1') cnt1++;
            else cnt0++;
         }

         int take=0;

         int not_take=0;
          
         if(m-cnt0>=0 and n-cnt1>=0)
         {
           take=1+solve(nums,m-cnt0,n-cnt1,i+1);  
         }

         not_take=0+solve(nums,m,n,i+1);

         return dp[i][m][n]=max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {

        int size=strs.size();

        memset(dp,-1,sizeof(dp));

        return solve(strs,m,n,0);
    }
};