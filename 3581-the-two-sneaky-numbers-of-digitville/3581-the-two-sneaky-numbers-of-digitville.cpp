class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        int n=nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        vector<int>vec;

        for(auto m:mp)
        {
            if(m.second>1) vec.push_back(m.first);
        }

        return vec;
        
    }
};