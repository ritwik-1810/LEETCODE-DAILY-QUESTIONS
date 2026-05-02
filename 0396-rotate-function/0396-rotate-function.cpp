class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

       int size = nums.size();

       int sum = 0;

       for(int i=0;i<size;i++)
       {
          sum+=nums[i];
       }

       int fk=0;

       for(int i=0;i<size;i++)
       {
          fk+=i*nums[i];
       }

       int maximum=fk;

       for(int i=1;i<size;i++)
       {
          int fi=fk+sum-(size*nums[size-i]);

          maximum=max(maximum,fi);

          fk=fi;
       }

       return maximum;
        
    }
};