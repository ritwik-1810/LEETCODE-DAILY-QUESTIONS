class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int majority = nums[0];

        int majCount= 1;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=majority)
            {
                majCount--;

                if(majCount==0)
                {
                    majority=nums[i];

                    majCount=1;
                }
            }
            else
            {
                majCount++;
            }
        }

        
        return majority;
    }
};