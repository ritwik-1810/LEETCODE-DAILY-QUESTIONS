class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        unordered_map<int,long long>mp;

        unordered_map<int,long long>mp1;

        unordered_map<int ,int>freq;

        unordered_map<int ,int>freq1;

        int size=nums.size();

        vector<long long>ans(size);

        for(int i=0;i<nums.size();i++)
        {
           mp[nums[i]]+=i;

           freq[nums[i]]+=1;
        }

        for(int i=0;i<nums.size();i++)
        {
            long long val=0;


            if(freq[nums[i]]>1)
            {
                long long f1=freq1[nums[i]];

                long long s1=mp1[nums[i]];

                long long left=(i*f1)-s1;


                long long f2=freq[nums[i]]-freq1[nums[i]]-1;

                long long s2=mp[nums[i]]-mp1[nums[i]]-i;

                long long right=s2-(i*f2);

                val=left+right;

            }

            mp1[nums[i]]+=i;
            freq1[nums[i]]++;
            ans[i]=val;
        }
        

        return ans;
    }
};