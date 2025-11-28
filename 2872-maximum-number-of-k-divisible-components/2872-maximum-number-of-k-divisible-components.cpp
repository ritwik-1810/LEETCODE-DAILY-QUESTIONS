class Solution {
public:
    long long dfs(int i , unordered_map<int,vector<int>>&adj , vector<bool>&vis , vector<int>& values , int k ,int &cnt)
    {
         vis[i]=true;

         long long sum=values[i];

         for(auto t:adj[i])
         {
              if(!vis[t])
              {
                long long children = dfs(t,adj,vis,values,k,cnt);

                sum+=children;

              }
              
         }

         if(sum%k==0) {

                 cnt++;

                 return 0;  

         }

         return sum;

         
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        int size = values.size();

        unordered_map<int,vector<int>>adj;

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];

            int v = edges[i][1];

            adj[u].push_back(v);

            adj[v].push_back(u);
        }

        int cnt=0;

        vector<bool>vis(size,false);

        long long sum=dfs(0,adj,vis,values,k,cnt);

        return cnt;
        
    }
};