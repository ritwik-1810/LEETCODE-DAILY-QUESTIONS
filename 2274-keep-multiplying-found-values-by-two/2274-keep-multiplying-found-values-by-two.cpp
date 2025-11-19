class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        int size = nums.size();

        sort(begin(nums),end(nums));

        for(int i = 0 ; i < size ; i++)
        {
            if(nums[i]==original)
            {
                original=2*original;
            }
        }

        return original;


        
    }
};