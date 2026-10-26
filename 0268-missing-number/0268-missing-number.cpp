class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int sum1=0;

        for(int i=0;i<nums.size();i++)
        {
            sum1+=nums[i];
        }

        int n=nums.size();

        int sum2=(n*(n+1))/2;

        return sum2-sum1;
        
    }
};