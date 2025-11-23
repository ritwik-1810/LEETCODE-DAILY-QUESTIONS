class Solution {
public:

    int solve(vector<int>&nums,int i,int size,int rem,vector<vector<int>>&dp)
    {
        if(i>=size)
        {
            if(rem==0) return 0;

            return INT_MIN;
        }

        if(dp[i][rem]!=-1)
          return dp[i][rem];
         
        int take=nums[i] + solve(nums,i+1,size,(rem+nums[i])%3,dp);

        int not_take=0 + solve(nums,i+1,size,rem,dp);

        return dp[i][rem]=max(take,not_take);
    }
    int maxSumDivThree(vector<int>& nums) {

        int size=nums.size();

        vector<vector<int>>dp(size,vector<int>(3,-1));

        return solve(nums,0,size,0,dp);

    }
};