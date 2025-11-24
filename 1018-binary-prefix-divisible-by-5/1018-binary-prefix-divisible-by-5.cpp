class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        int size = nums.size();

        vector<bool>ans(size,false);

        vector<int>vec(size,0);

        int prev=0;

        for(int i=0;i<size;i++)
        {
            vec[i] = ((2*prev)+nums[i])%5;

            prev = vec[i];
        }

        for(int i = 0 ; i < size ; i++)
        {
            if(vec[i]%5==0)
             ans[i]=true;
        }

        return ans;
        
    }
};