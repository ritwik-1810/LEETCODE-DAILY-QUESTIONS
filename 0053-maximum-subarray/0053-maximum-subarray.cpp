class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        /*Simple Logic of kadane algo is ---> currmax = max(current element , abhi tak ka sum),
           
          keep updating ans=max(previous max , currmax);

        */

        int curr=0;

        int ans=INT_MIN;

        for(auto c:nums)
        {
            curr=max(c,curr+c);

            ans=max(ans,curr);
        }

        return ans;
    }
};