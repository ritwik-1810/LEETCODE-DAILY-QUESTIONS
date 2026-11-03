class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int size = nums.size();

        long long maxi=LLONG_MIN;

        unordered_map<int,long long>mp;

        vector<long long>prefixSum(size);

        for(int i=0;i<size;i++)
        {
            prefixSum[i]= i>0 ? prefixSum[i-1]+nums[i] : nums[i];
        }


        for(int i=0;i<size;i++)
        {
            int a = k + nums[i];

            int b = nums[i] - k;
            
            if(mp.count(a))
            {  
               long long jSum=mp[a];
            
               maxi=max(maxi,prefixSum[i] - jSum);
            }
             
            if(mp.count(b))
            {
               long long j1Sum=mp[b];

               maxi=max(maxi,prefixSum[i] - j1Sum);
            }
            
            if(mp.count(nums[i]))
            {
                mp[nums[i]]=min(i==0 ? 0 : prefixSum[i-1],mp[nums[i]]);
            }
            else
            {
                mp[nums[i]] = i==0 ? 0 : prefixSum[i-1];
            }
        }

        return maxi==LLONG_MIN ? 0 : maxi;

    }
};