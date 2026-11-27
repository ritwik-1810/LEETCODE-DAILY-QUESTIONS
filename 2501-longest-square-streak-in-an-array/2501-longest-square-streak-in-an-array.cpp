class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        int size = nums.size();

        sort(nums.begin(),nums.end());

        vector<int>maxCnt(size,1);

        for(int i=0;i<size;i++)
        {
            long long sq = 1LL * nums[i]*nums[i];

            int  idx = lower_bound(nums.begin(),nums.end(),sq) - nums.begin();

            if(idx<size)
            {
                if(nums[idx]==sq && maxCnt[idx]==1)
                {
                    maxCnt[idx]+=maxCnt[i];
                }
            }
        }
        
        int maxiAns=0;

        for(int i=0;i<size;i++)
        {
            maxiAns=max(maxiAns,maxCnt[i]);
        }

        if(maxiAns==1) return -1;

        return maxiAns;
    }
};