class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int size1 = nums1.size();

        int size2 = nums2.size();

        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>ans;

        set<pair<int,int>>vis;

        int sum=nums1[0] + nums2[0];

        pq.push({sum,{0,0}});

        while(!pq.empty() && k--)
        {
           int s=pq.top().first;

           int i=pq.top().second.first;

           int j=pq.top().second.second;

           ans.push_back({nums1[i],nums2[j]});

           pq.pop();

           int s1=INT_MAX;

           int s2=INT_MAX;

           if(i+1<nums1.size() && !vis.count({i+1,j}))
           {
              s1=nums1[i+1]+nums2[j];
              
               pq.push({s1,{i+1,j}});

               vis.insert({i+1,j});

           }

           if(j+1<nums2.size() && !vis.count({i,j+1}))
           {
               s2=nums1[i]+nums2[j+1];

               pq.push({s2,{i,j+1}});

               vis.insert({i,j+1});
           }
           

           
        }

        return ans;

    }
};