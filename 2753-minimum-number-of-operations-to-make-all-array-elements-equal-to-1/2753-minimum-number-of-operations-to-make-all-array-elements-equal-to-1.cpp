class Solution {
public:
    int minOperations(vector<int>& nums) {

        int size=nums.size();

        bool ans=false;

        int cnt=0;

        int mini=INT_MAX;

        int c=0;

        for(int i=0;i<size;i++)
        {
            if(nums[i]==1)
             c++;
        }

        if(c>0) return size-c;

        for(int i=0;i<size-1;i++)
        {
            cnt=0;

            int g=nums[i];

            for(int j=i+1;j<size;j++)
            {
               g=__gcd(g,nums[j]);
                cnt+=1;

               if(g==1) 
               {
                  mini=min(cnt,mini);
                  break;
               }
            }
            
            
        }

        if(mini==INT_MAX) return -1;

        return (size-1)+(mini);

        

    }
};