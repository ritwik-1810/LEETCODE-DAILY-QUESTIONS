class Solution {
public:
     void solve(vector<int>& nums,int i,vector<vector<int>>&ans,vector<int>&vec)
    {
        if(i>=nums.size())
        {
            ans.push_back(vec);
            return;
        }


        vec.push_back(nums[i]);

        solve(nums,i+1,ans,vec);
        
        vec.pop_back();
        
        solve(nums,i+1,ans,vec);

    }
    vector<vector<int>> subsets(vector<int>& nums) {

        int size = nums.size();

        vector<vector<int>>ans;

        vector<int>vec;

        solve(nums,0,ans,vec);

        return ans;

    }
};