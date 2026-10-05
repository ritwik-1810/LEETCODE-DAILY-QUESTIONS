class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int size=nums.size();

        unordered_map<int,int>vec;

        for(int i=0;i<size;i++)
        {   
            if(nums[i]>0)
            vec[nums[i]]++;
        }

        int smallest=1;

        while(true)
        {
            if(!vec.count(smallest))
            {
                return smallest;
            }

            smallest+=1;
        }

        return -1;
        
    }
};