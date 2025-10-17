class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        int size=nums.size();

        unordered_map<int , int>mp;


        for(int i=0;i<size;i++)
        {
            if(nums[i]>=0)
            {
               int a=nums[i]%value;

               mp[a]++;
            }
            else
            {
                int b=(nums[i]%value+value)%value;

                mp[b]++;

            }
        }

       
        int mex=0;

        while(true)
        {
            if(mp[mex%value]==0)
            {
                return mex;
            }
            else
            {
                mp[mex%value]--;
                mex++;
            }
        }

        return -1;

    }
};