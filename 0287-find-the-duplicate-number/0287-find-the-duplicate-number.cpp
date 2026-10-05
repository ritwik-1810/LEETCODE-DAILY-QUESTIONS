class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int size=nums.size();

        for(int i=0;i<size;i++)
        {
            int pivot=abs(nums[i]);

            if(nums[pivot]<0) return pivot;

            nums[pivot]*=-1;
        }

        return -1;
        
    }
};