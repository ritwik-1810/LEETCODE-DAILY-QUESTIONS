class Solution {
public:
    int largestPerimeter(vector<int>& nums) {


        int size=nums.size();

        int maxi_para=0;

        sort(nums.begin(),nums.end());

    

        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                int sum=nums[i]+nums[j];

                int k=j+1;

                while(k<size && sum<=nums[k])
                {
                    k++;
                }

               if(k<size)
               {
                  int val=sum+nums[k];

                   maxi_para=max(maxi_para,val);  

               }    
            
             
            
            }
        }

       return maxi_para;
        
    }
};