class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int size=nums.size();

        int slow=0;

        int fast=0;

        while(true)
        {
            slow=nums[slow];

            fast=nums[nums[fast]];

            if(slow==fast) break;
        }

        int p=0;

        while(nums[p]!=nums[slow])
        {
            p=nums[p];

            slow=nums[slow];
        }

        return nums[slow];
        
    }
};