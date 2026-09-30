class Solution {
public:
    void solve(vector<int>& candidates, int target,int idx,vector<int>&temp,

         vector<vector<int>>&ans,set<vector<int>>&st)
    {
        if(target<0) return;

        if(target==0)
        {
            ans.push_back(temp);
        }

        for(int i=idx;i<candidates.size();i++)
        {
            if(i > idx && candidates[i] == candidates[i-1])
                continue;
            
            temp.push_back(candidates[i]);

            solve(candidates,target-candidates[i],i+1,temp,ans,st);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         
         vector<int>temp;

         vector<vector<int>>ans;

         set<vector<int>>st;

         sort(candidates.begin(),candidates.end());

         solve(candidates,target,0,temp,ans,st);

         return ans;

    }
};