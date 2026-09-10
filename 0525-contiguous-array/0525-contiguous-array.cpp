class Solution {
public:
    int findMaxLength(vector<int>& nums) {

       /* intuition -->
       think --> if a subarray has equal number of zero and one then they can cancel each other and we get empty array

       now when i say cancel we know that one cannot cancel 0 so what if we make 0 as -1 so when we take cummulative sum we can get 0 as answer

       now the question comes down to maximum subarray with sum 0 pattern

       use hashmap + prefixsum 
       */

       int size=nums.size();
       
       unordered_map<int,int>mp;  //store sum, indx;

       for(int i=0;i<size;i++)
       {
          if(nums[i]==0) nums[i]=-1;
       }

       mp[0]=-1;

       int maxi=0;

       int sum=0;

       for(int i=0;i<size;i++)
       {
           sum+=nums[i];

           if(mp.count(sum))
           {

              maxi=max(maxi,i-mp[sum]);
              
           }
           else
           {
               mp[sum]=i;
           }
       }
         

       return maxi;

        
    }
};