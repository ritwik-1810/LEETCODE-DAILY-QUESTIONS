class Solution {
public:
    int minMoves(vector<int>& nums) {

        int size = nums.size();

        int mini = INT_MAX;

        for(int i=0;i<size;i++)
        {
            mini = min(mini,nums[i]);
        }

        int cnt=0;

        for(int i=0;i<size;i++)
        {
            cnt+=nums[i]-mini;
        }

        return cnt;
        
    }
};