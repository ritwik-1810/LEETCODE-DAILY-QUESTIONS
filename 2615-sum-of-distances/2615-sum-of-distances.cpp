class Solution {
public:
    vector<long long> distance(vector<int>& nums) {

        unordered_map<int,long long>totalSum;

        unordered_map<int,long long>leftSum;

        unordered_map<int ,int>totalFreq;

        unordered_map<int ,int>leftFreq;

        int size=nums.size();

        vector<long long>ans(size);

        for(int i=0;i<nums.size();i++)
        {
           totalSum[nums[i]]+=i;

           totalFreq[nums[i]]+=1;
        }

        for(int i=0;i<nums.size();i++)
        {
            long long val=0;

            if(totalFreq[nums[i]]>1)
            {
                long long f1=leftFreq[nums[i]];

                long long s1=leftSum[nums[i]];

                long long left=(i*f1)-s1;


                long long f2=totalFreq[nums[i]]-leftFreq[nums[i]]-1;

                long long s2=totalSum[nums[i]]-leftSum[nums[i]]-i;

                long long right=s2-(i*f2);

                val=left+right;

            }

            leftSum[nums[i]]+=i;
            leftFreq[nums[i]]++;
            ans[i]=val;
        }
        

        return ans;
    }
};