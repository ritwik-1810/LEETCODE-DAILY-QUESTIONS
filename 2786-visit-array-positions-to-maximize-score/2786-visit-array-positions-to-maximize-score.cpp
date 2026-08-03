class Solution {
public:
    long long solve(vector<int>&nums , int i , int x , vector<long long>&dp,vector<int>&even,vector<int>&odd)
    {
        if(i>=nums.size())
        {
            return 0;
        }

        if(dp[i]!=-1) return dp[i];

        long long diff=0;

        long long same=0;

        int j=i+1;

        int k=i+1;

        if(nums[i]%2==0)
        {
           j=even[i+1];

           k=odd[i+1];
        }
        else
        {
           k=even[i+1];

           j=odd[i+1];
        }
        
        if(j<nums.size())
        same = nums[j] + solve(nums,j,x,dp,even,odd);

        if(k<nums.size())
        {
            diff = nums[k] - x + solve(nums,k,x,dp,even,odd);
        }

        return dp[i] = max(same,diff);
    }
    long long maxScore(vector<int>& nums, int x) {

        int size = nums.size();

        vector<long long>dp(size,-1);

        vector<int>even(size+1,0);

        even[size]=size;

        for(int i=size-1;i>=0;i--)
        {
            if(nums[i]%2==0)
            {
                even[i]=i;
            }
            else
            {
                even[i]=even[i+1];
            }
        }

        vector<int>odd(size+1,0);

        odd[size]=size;

        for(int i=size-1;i>=0;i--)
        {
            if(nums[i]%2!=0)
            {
                odd[i]=i;
            }
            else
            {
                odd[i]=odd[i+1];
            }
        }

        return nums[0] + solve(nums,0,x,dp,even,odd);
        
    }
};