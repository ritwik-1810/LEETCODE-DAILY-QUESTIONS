class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
          
        int size = nums.size();

        vector<int>diff(size+1,0);

        int curr = 0;

        for(int i=0;i<size;i++)
        {
           curr+=diff[i];

           nums[i]=nums[i]+curr;

           if(nums[i]==0) continue;

           if(nums[i]<0) return false;

           if(i+k>size) return false;

           curr-=nums[i];

           diff[i+k]=nums[i];

        }
         
        return true;
        
    }
};