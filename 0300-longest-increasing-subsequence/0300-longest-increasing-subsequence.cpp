class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int size=nums.size();

        vector<int>ans;

        for(int i=0;i<size;i++)
        {
            int val=nums[i];

            int idx=lower_bound(ans.begin(),ans.end(),val)-ans.begin();

            if(idx==ans.size())
            {
                ans.push_back(val);
            }
            else
            {
                ans[idx]=val;
            }
        }
        

        return ans.size();
    }
};