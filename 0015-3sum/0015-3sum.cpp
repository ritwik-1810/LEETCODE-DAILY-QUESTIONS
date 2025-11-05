class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int size=nums.size();

        int j=1;

        sort(begin(nums),end(nums));

        set<vector<int>>s;

        vector<vector<int>>ans;

        for(int i=0;i<size-2;i++)
        {
             int a=nums[i];

            for(int j=i+1;j<size-1;j++)
            {
                int b=nums[j];

                int val=0-(a+b);

                int k = lower_bound(nums.begin() + j + 1,nums.end(),val) - nums.begin();

                if(k==size) continue;
                
                int c=nums[k];
                  
                  if((a+b+c)==0)
                  {
                    vector<int> triplet = {a, b, c};
                    sort(triplet.begin(), triplet.end());
                    s.insert(triplet);
                  }

            }
        }

        for(auto v:s)
        {
            ans.push_back(v);
        }

        return ans;
        
    }
};