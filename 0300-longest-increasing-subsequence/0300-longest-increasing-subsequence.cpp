class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int size=nums.size();

        vector<int>ans(size,1);

        set<int>a;

        for(int i=0;i<size;i++)
        {
            a.insert(nums[i]);
        }

        if(a.size()==1) return 1;

        int prev=-1;

        for(int i=0;i<size;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    ans[i]=max(ans[i],ans[j]+1);
                }
            }
        }

        int maxi=0;

        for(int i=0;i<size;i++)
        {
            maxi=max(maxi,ans[i]);
        }

        return maxi;
        
        
    }
};