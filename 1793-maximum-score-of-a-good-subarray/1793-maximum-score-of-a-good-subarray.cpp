class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        int size=nums.size();

        int maxi = nums[k];

        int i=k;

        int j=k;

        int mini=nums[k];

        while(i>0 || j<size-1)
        {
           if(i==0)
           {
               mini=min(mini,nums[j+1]);

               j++;
               
               maxi=max(maxi,mini*(j-i+1));

           }
           else if(j==size-1)
           {
               mini=min(mini,nums[i-1]);

               i--;
               
               maxi=max(maxi,mini*(j-i+1));

           }
           else
           {
               if(nums[i-1]>nums[j+1])
               {
                   mini=min(mini,nums[i-1]);
                   i--;
               }
               else if(nums[i-1]<=nums[j+1])
               {
                   mini=min(mini,nums[j+1]);
                   j++;
               }

               maxi=max(maxi,mini*(j-i+1));
               
           }
        }

       return maxi;
        
    }
};