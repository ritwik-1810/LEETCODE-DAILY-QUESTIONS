class Solution {
public:
    int minJumps(vector<int>& arr) {

        int s = arr.size();

        unordered_map<int,vector<int>>mp;

        int lastIdx=s-1;

        for(int i=0;i<s;i++)
        {
            mp[arr[i]].push_back(i);
        }

        vector<bool>vis(s,false);

        int mini=INT_MAX;

        queue<pair<int,int>>q;

        q.push({0,0});

        vis[0]=true;

        while(!q.empty())
        {
           auto [idx,dis] = q.front();

           if(idx==lastIdx) mini=min(mini,dis);

           vis[idx]=true;

           q.pop();

           if(idx-1>=0 && !vis[idx-1])
           {
              q.push({idx-1,dis+1});
           }

           if(idx+1<s && !vis[idx+1])
           {
              q.push({idx+1,dis+1});
           }

           for(auto d:mp[arr[idx]])
           {
              if(vis[d]==false)
              {
                 q.push({d,dis+1});
              }
           }

            mp[arr[idx]].clear();

        }

        return mini;
        
    }
};