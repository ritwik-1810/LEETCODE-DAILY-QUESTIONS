class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int size=nums.size();

        vector<int>ans;

        ans.push_back(nums[0]);

        for(int i=1;i<size;i++)
        {
            int val=nums[i];

            auto idx=lower_bound(ans.begin(),ans.end(),val);

            if(idx==ans.end())
            {
               ans.push_back(val);
            }
            else
            {
                ans[idx-ans.begin()]=val;
            }

        }

        return ans.size();
        
        
    }
};