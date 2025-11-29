class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int size=nums.size();

        int sum=0;

        for(int i=0;i<size;i++)
        {
            sum+=nums[i];
        }

        return sum%k;
        
    }
};