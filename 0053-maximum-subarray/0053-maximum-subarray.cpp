class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int size=nums.size();

        int maxi=INT_MIN;

        int sum=0;

        int cnt=0;

        int mi=INT_MIN;

        for(int i=0;i<size;i++)
        {
            if(nums[i]<0)
             cnt+=1;
            
            mi=max(mi,nums[i]);
            
        }

        if(cnt==size) return mi;
        
        for(int i=0;i<size;i++)
        {
            sum+=nums[i];

            if(sum<0)
            {
                sum=0;
            }

            maxi=max(sum,maxi);
        }

        return maxi;

        
    }
};