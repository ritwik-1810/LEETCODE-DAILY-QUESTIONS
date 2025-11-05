class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

         int size=nums.size();

        int j=1;

        sort(begin(nums),end(nums));

        set<vector<int>>s;

        vector<vector<int>>ans;

        for(int i=0;i<size-3;i++)
        {
            int a=nums[i];

            for(int j=i+1;j<size-2;j++)
            {
                int b=nums[j];

                for(int k=j+1;k<size;k++)
                {
                   int c=nums[k];

                long long val=(long long)target-((long long)a+b+c);

                int l = lower_bound(nums.begin() + k + 1,nums.end(),val) - nums.begin();

                if(l==size) continue;
                
                int d=nums[l];
                  
                  if(((long long)a+b+c+d)==target)
                  {

                    vector<int> triplet = {a, b, c,d};
                    sort(triplet.begin(), triplet.end());
                    s.insert(triplet);

                  }

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