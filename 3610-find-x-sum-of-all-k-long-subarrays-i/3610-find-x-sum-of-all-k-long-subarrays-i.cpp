class Solution {
public:
    static bool mycomp(pair<int,int>&a,pair<int,int>&b)
    {

         if(a.first==b.first)
          return a.second>b.second;

         return a.first>b.first;

    }
    int solve(unordered_map<int,int>mp,int x)
    {
        vector<pair<int,int>>vec;

        for(auto v:mp)
        {
            vec.push_back({v.second,v.first});
        }

        sort(vec.begin(),vec.end(),mycomp);

        int size=vec.size();

        int ans=0;

        for(int i=0;i<size;i++)
        {
            cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }

        for(int i=0;i<min(size,x);i++)
        {
            auto [fr,sr]=vec[i];

            ans+=(fr*sr);
        }
       
        return ans;

    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {

        vector<int>ans;

        int size=nums.size();

        unordered_map<int , int>mp;

        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
        }
        
        for(int i=0;i<=size-k;i++)
        {
            int val=solve(mp,x);

            ans.push_back(val);

            mp[nums[i]]--;

            if(mp[nums[i]]==0)
              mp.erase(nums[i]);
            
            if(i+k<size)
            mp[nums[i+k]]++;
        }

        return ans;
        
    }
};