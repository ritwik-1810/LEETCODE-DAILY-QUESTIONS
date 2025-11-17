class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int size=nums.size();

        int i=0;

        int j=0;

        while(i<size && nums[i]!=1)  i++;

        j=i+1;
        
        while(j<size)
        {
            while(j<size && nums[j]!=1)
            {
                 j++;
            }

            if(j<size)
            {
                if(j-i-1<k) return false;
            }

            i=j;

            j++;
        }


        return true;
        
    }
};