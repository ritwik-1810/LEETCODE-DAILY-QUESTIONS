class Solution {
public:
    int dp[1001][1501][2];

    int findMaximumItems(int i,vector<vector<int>>& items,vector<int>&freeItems,bool taken,int budget)
    {
        if(i>=items.size()) return 0;

        if(dp[i][budget][taken]!=-1) return dp[i][budget][taken];

        int take=0;

        int notTake=0;

        if(budget-items[i][1]>=0)
        {
          if(taken==false)
          {
             take = 1 + freeItems[i] + findMaximumItems(i,items,freeItems,true,budget-items[i][1]);
          }
          else
          {
             take = 1 + findMaximumItems(i,items,freeItems,true,budget-items[i][1]);
          }

            notTake = 0 + findMaximumItems(i+1,items,freeItems,false,budget);
        }
        else
        {
            notTake= 0 + findMaximumItems(i+1,items,freeItems,false,budget);
        }
        
        return dp[i][budget][taken] = max(take,notTake);

    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int size = items.size();

        vector<int>freeItems(size,0);

        memset(dp, -1, sizeof(dp)); 

        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(i==j) continue;

                if(items[j][0]%items[i][0]==0)
                {
                    freeItems[i]+=1;
                }
            }
        }

        for(int i=size-1;i>=0;i--)
        {
            int price = items[i][1];

            for(int b = 0 ; b<=budget ; b++)
            {
                for(int t = 0;t<=1;t++)
                {
                     int take=0;

        int notTake=0;

        if(b-items[i][1]>=0)
        {
          if(t==false)
          {
             take = 1 + freeItems[i] + dp[i][b-price][1];
          }
          else
          {
             take = 1 + dp[i][b-price][1];
          }

            notTake = 0 + dp[i+1][b][0];
        }
        else
        {
            notTake= 0 + dp[i+1][b][0];
        }

         dp[i][b][t] = max(take,notTake);
        
                }
            }
        }

        return dp[0][budget][0];

        //return findMaximumItems(0,items,freeItems,false,budget);
        
    }
};