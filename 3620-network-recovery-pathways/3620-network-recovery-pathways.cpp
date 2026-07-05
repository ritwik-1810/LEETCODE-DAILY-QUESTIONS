class Solution {
public:
    bool bfs(unordered_map<int,vector<vector<int>>>&adj,vector<bool>& online,int mid,long long k)
    {
         priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;

         int size = online.size();

         vector<long long>vis(size,LLONG_MAX);

         vis[0]=0;

         q.push({0,0});

         while(!q.empty())
         {
             auto [total,u] = q.top();

             q.pop();

             if (total > vis[u]) continue;

             if(u==size-1) return true;

             for(auto &d:adj[u])
             {
                int v=d[0];

                int cost=d[1];

                if(cost>=mid  && total+cost<=k && total+cost<vis[v] && online[v]==true)
                {
                   vis[v]=total+cost;

                   long long f=total+cost;

                   q.push({f,v});
                }
             }
         }

         return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        unordered_map<int,vector<vector<int>>>adj;

        int end=0;

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            
            int v = edges[i][1];

            int cost = edges[i][2];

            end=max(end,cost);

            adj[u].push_back({v,cost});
        }

        int start=0;

        int ans=-1;

        while(start<=end)
        {
            int mid = start + (end-start)/2;

            if(bfs(adj,online,mid,k))
            {
                ans=mid;

                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }


        return ans;
    }
};