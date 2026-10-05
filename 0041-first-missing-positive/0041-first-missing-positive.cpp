class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int size=nums.size();

        bool containOne=false;

        for(int i=0;i<size;i++)
        {
            if(nums[i]==1)
             containOne=true;

             if(nums[i]<=0)
             {
                nums[i]=1;
             }
        }

        if(!containOne) return 1;
        
        int i=0;

        for(;i<size;i++)
        {
            int num=abs(nums[i]);

            int idx=num-1;

            if(idx>=size) continue;

            if(nums[idx]>0)
            {
                nums[idx]*=-1;
            }

            
        }

        for(i=0;i<size;i++)
        {
            if(nums[i]>0)
              return i+1;
        }

        return size+1;
        
    }
};