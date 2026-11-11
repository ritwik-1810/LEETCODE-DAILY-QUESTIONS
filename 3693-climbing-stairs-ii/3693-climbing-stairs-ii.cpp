class Solution {
public:
    int dp[100001];
    int solve(int size,int i,vector<int>& costs)
    {
        if(i==size) return 0;

        if(dp[i]!=-1) return dp[i];

        int ans = 0;

        int mini=INT_MAX;

        int j = i+1;

        if(j<=size)
        {
           ans=costs[j-1] + (j-i)*(j-i) + solve(size,i+1,costs); 
        }

        mini=min(ans,mini);

        j = i+2;
        
        if(j<=size)
        {
           ans=costs[j-1] + (j-i)*(j-i) + solve(size,i+2,costs); 
        }

         mini=min(ans,mini);

        j = i+3;

        if(j<=size)
        {
           ans=costs[j-1] + (j-i)*(j-i) + solve(size,i+3,costs); 
        }

         mini=min(ans,mini);

         return dp[i] = mini;
        
    }
    int climbStairs(int n, vector<int>& costs) {

        int size = costs.size();

        memset(dp,-1,sizeof(dp));

        return solve(size,0,costs);
        
        
    }
};