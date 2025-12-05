class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int size=nums.size();

        int count=0;

        for(int i=1;i<size;i++)
        {
            nums[i]+=nums[i-1];
        }

        for(int i=0;i<size-1;i++)
        {
            if(abs(nums[i]-(nums[size-1]-nums[i]))%2==0)
             count+=1;
        }        
        return count;
    }
};