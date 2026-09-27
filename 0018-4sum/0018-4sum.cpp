class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

      int size = nums.size();
        
        sort(nums.begin(),nums.end());

        set<tuple<int,int,int,int>>st;

        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                int s=size-1;

                int sum1=nums[i]+nums[j];

                int k=j+1;

                while(k<s)
                {
                    if((long long)sum1+nums[k]+nums[s]==target)
                    {
                       st.insert({nums[i],nums[j],nums[k],nums[s]});
                       k++;
                    }
                    else if((long long)sum1+nums[k]+nums[s]>target)
                    {
                        s--;
                    }
                    else
                    {
                        k++;
                    }
                }
            }
        }

        
        vector<vector<int>>ans;

        for(auto [a,b,c,d]:st)
        {
            ans.push_back({a,b,c,d});
        }
        
        return ans;
        
        
        
    }
};