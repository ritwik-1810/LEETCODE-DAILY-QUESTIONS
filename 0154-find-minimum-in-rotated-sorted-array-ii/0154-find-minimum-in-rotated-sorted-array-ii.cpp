class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int size_=nums.size();

        int start=0;
        int end=size_-1;
        int mid;
        int index=-1;

        while(start<end)
        {
            mid=start+(end-start)/2;

            if(nums[mid]>nums[end])
            {
                start=mid+1;
            }
            else if(nums[mid]<nums[end])
            {
                end=mid;
            }
            else 
            {
                end--;
            }

        }

        return nums[end];
    }
};