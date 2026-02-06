class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {

        map<long long,long long>mp;

        int size = segments.size();

        for(int i=0 ; i < size ; i++)
        {
            int start = segments[i][0];

            int end = segments[i][1];

            int val = segments[i][2];

            mp[start]+=val;

            mp[end]-=val;
        }

        vector<vector<long long>>ans;

        long long count=0;

        for(auto it=mp.begin();next(it)!=mp.end();it++)
        {
            long long fir=it->first;

            long long sec=next(it)->first;

            count+=it->second;

            if(count==0) continue;

            ans.push_back({fir,sec,count});
        }

        return ans;
    }
};