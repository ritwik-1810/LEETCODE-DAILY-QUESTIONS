class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int size=nums.size();

        vector<int>ans;

        unordered_map<int,int>mp;

        for(int i=0;i<size;i++)
        {
            mp[nums[i]]++;
        }

        int maxi=0;

        for(auto v:mp)
        {
            maxi=max(v.second,maxi);
        }

        unordered_map<int,vector<int>>mp1;

        for(auto v:mp)
        {
           mp1[v.second].push_back(v.first);
        }

        while(maxi && k)
        {
            if(mp1.find(maxi)!=mp1.end())
            {
                for(auto v:mp1[maxi])
                {
                ans.push_back(v);
                k--;
                }
            } 
         
            maxi--;
        }

        return ans;
        
    }
};