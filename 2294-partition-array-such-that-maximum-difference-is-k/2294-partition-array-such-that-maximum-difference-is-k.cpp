class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {

        int n = nums.size();

        int count = 0;

        sort(nums.begin(),nums.end());
        
        int i=0;

        bool flag=false;

        while(i < n)
        {
            int j=i+1;

            while(j<n && (nums[j]-nums[i])<=k)
            {
                j++;
            }
               
               if(j<n)
               {
                 flag=true;
                 count+=1;
               }

               i=j;

        }

        return  count+1;
        
    }
};