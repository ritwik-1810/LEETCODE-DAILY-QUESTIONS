class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int size=nums.size();

        int maxi=INT_MIN;

        int preprod=1;

        int sufprod=1;

        for(int i=0;i<nums.size();i++)
        {
            if(preprod==0)
            {
                preprod=1;
                
            }

            if(sufprod==0)
            {
                sufprod=1;
            }
            
            preprod*=nums[i];

            sufprod*=nums[size-i-1];

            maxi=max(maxi,max(preprod,sufprod));
            
        }

        return maxi;

    }
};