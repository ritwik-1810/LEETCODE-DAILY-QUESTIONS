class Solution {
public:
    long long dp[1001][501][3];
    long long solve(vector<int>& prices,int k,int idx,int mode)
    {
        
        if(idx>=prices.size())
        {
            if(mode==0) return 0;

            return INT_MIN; 
        }
        
         if (dp[idx][k][mode] != -1)
            return dp[idx][k][mode];


        long long notTake=solve(prices,k,idx+1,mode);

        long long take=0;

        if(k>0)
        {
        if(mode==1)
        {
            take=-prices[idx] + solve(prices,k-1,idx+1,0);
        }
        else if(mode==2)
        {
            take=prices[idx] + solve(prices,k-1,idx+1,0);
        }
        else
        { 
            take=max(-prices[idx] + solve(prices,k,idx+1,2),
        
            prices[idx] + solve(prices,k,idx+1,1));
        }
        }

        return dp[idx][k][mode] = max(take,notTake);

    }
    long long maximumProfit(vector<int>& prices, int k) {

        int size = prices.size();

        memset(dp, -1, sizeof(dp));

        return solve(prices,k,0,0);
        
    }
};