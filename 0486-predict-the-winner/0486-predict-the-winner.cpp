class Solution {
public:
    int solve(vector<int>&nums,int i,int j,int pl,int sl,int s)
    {
        if(i>j)
        {
            if(pl>=sl) return true;

            return false;
        }

        
        bool left=false;

        bool right=false;

        if(s==0)
        {
            return solve(nums,i+1,j,pl+nums[i],sl,1) || solve(nums,i,j-1,pl+nums[j],sl,1);



        }
        else
        {   

            return solve(nums,i+1,j,pl,sl+nums[i],0) && solve(nums,i,j-1,pl,sl+nums[j],0);

        }

        return left || right;
      
    }
    bool predictTheWinner(vector<int>& nums) {

        int size=nums.size();

        int i=0;

        int j=size-1;

        return solve(nums,i,j,0,0,0);
        
    }
};