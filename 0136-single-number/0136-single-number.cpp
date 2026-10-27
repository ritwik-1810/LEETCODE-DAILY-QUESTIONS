class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int size = nums.size();

        int SingleNumber=0;

        for(int i=0;i<size;i++)
        {
            SingleNumber^=nums[i];
        }
        
        return SingleNumber;

    }
};