class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

         int xr=0;

         for(int i=0;i<nums.size();i++)
         {
            xr^=nums[i];
         }

         int basket1=0;

         int basket2=0;

         int idx=0;

         for(int i=0;i<32;i++)
         {
             if((xr>>idx)&1 == 1) break;

             idx+=1;
         }

         for(int i=0;i<nums.size();i++)
         {
              if((nums[i]>>idx) & 1 == 1) basket1^=nums[i];
              else basket2^=nums[i];
         }
         
         return {basket1,basket2};
        
    }
};