class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

        long long minimumCount=0;

        int n=nums.size()-1;

        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                long long part = nums[i]/nums[i+1];

                if((nums[i]%nums[i+1])!=0)
                {
                    part++;
                }

                minimumCount+=part-1;

                nums[i]=nums[i]/part;
            }
        }

        return minimumCount;
        
    }
};