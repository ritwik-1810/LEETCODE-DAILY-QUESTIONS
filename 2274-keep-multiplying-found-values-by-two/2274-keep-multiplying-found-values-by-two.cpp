class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {

        //brute force approach-->

         int size = nums.size();

        // sort(begin(nums),end(nums));

        // for(int i = 0 ; i < size ; i++)
        // {
        //     if(nums[i]==original)
        //     {
        //         original=2*original;
        //     }
        // }

        // return original;

        //optimized approach --->

        unordered_map<int,int>mp;

        for(int i=0;i<size;i++)
        {
            mp[nums[i]]++;
        }

        for(auto v:mp)
        {
            if(mp.find(original) == mp.end())
            {
                 return original;
            }

            original=2*original;
        }
        

        return original;

    }
};