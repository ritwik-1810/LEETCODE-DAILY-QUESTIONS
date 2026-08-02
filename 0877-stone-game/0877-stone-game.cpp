class Solution {
public:
        int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }

        if(i==j)
        {
            return nums[i];
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int take_i=nums[i] + min(solve(nums,i+2,j,dp),solve(nums,i+1,j-1,dp));

        int take_j=nums[j] + min(solve(nums,i,j-2,dp),solve(nums,i+1,j-1,dp));

        return dp[i][j] = max(take_i,take_j);
       
    }
        
    bool stoneGame(vector<int>& piles) {

        int size = piles.size();

        int i=0;

        int j=size-1;

        vector<vector<int>>dp(size,vector<int>(size,-1));

        int sum = accumulate(piles.begin(),piles.end(),0);
       
        int aliceSum=solve(piles,0,j,dp);

        if((sum-aliceSum)>aliceSum) return false;

        return true;

    }
};