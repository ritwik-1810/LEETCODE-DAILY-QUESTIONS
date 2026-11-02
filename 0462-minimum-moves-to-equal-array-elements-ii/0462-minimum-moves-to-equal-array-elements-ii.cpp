class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int size = nums.size();

        int n1=-1;

        if(size%2==0)
        {
           n1=((nums[size/2] + nums[(size/2)-1]) / 2);
        }
        else
        {
           n1=nums[size/2];
        }

        int mini=0;

        for(int i=0;i<size;i++)
        {
            mini+=abs(nums[i]-n1);
        }

        return mini;
        
    }
};