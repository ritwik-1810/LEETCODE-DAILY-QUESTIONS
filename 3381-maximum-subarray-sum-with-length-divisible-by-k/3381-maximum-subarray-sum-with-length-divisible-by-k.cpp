class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        int size = nums.size();

        vector<long long>maxPre(k,LLONG_MAX);

        maxPre[0]=0;

        long long ans=LLONG_MIN;

        long long prefix=0;

        for(int i=0;i<size;i++)
        {
            prefix+=nums[i];

            int mod=(i+1)%k;

            if(maxPre[mod]!=LLONG_MAX)
            {
                ans=max(ans,prefix-maxPre[mod]);
            }

            maxPre[mod]=min(maxPre[mod],prefix);
        }

        return ans;
        
    }
};