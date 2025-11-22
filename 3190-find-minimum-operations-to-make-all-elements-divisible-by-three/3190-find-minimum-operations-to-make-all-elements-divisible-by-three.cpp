class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int size = nums.size();

        int ans=0;

        for(int i=0;i<size;i++)
        {
            if(nums[i]%3==0) continue;

            else ans+=1;
        }

        return ans;
        
    }
};