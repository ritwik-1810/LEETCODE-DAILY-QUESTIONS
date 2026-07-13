class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {

       int size = nums.size();

       if(size < k) return false;

       vector<int>preSum(size+1,0);

       int curr=0;

       for(int i=0;i<size;i++)
       {
          curr=curr-preSum[i];

          if(nums[i]-curr<0) return false;

          if(nums[i]-curr==0) continue;

          if(i+k>size) return false;

          preSum[i+k]+=(nums[i]-curr);

          curr+=(nums[i]-curr);
       }

       return true;
    }
};