class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

          int size = nums.size();

        unordered_map<int,int>preSumCnt;

        preSumCnt[0]=1;

        int totalCnt=0;

        int sum=0;

        for(int i=0;i<size;i++)
        { 
            sum+=nums[i];

    
            if(preSumCnt.count(sum-k))
            {
                totalCnt+=preSumCnt[sum-k];
            }
            
             preSumCnt[sum]++;
        }

        return totalCnt;
        
        
    }
};