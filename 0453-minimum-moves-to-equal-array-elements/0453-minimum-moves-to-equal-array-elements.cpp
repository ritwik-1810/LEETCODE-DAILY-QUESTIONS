class Solution {
public:
    int minMoves(vector<int>& nums) {

        int mini=INT_MAX;

        int size = nums.size();

         for(int i=0;i<size;i++)
         {
            mini=min(mini,nums[i]);
         }

        int ans=0;

        for(int i=0;i<size;i++)
        {
            ans+=(nums[i]-mini);
        }

        return ans;
        
    }
};