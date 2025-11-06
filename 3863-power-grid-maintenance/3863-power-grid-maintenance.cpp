class Solution {
public:
    void dfs(int id,unordered_map<int , vector<int>>&adj,vector<int>&vis,map<int , int>&mp,map<int , set<int>>&mpp,int i)
    {
        mp[i]=id;

        mpp[id].insert(i);

        vis[i]=true;

        for(auto v:adj[i])
        {
            if(!vis[v])
              dfs(id,adj,vis,mp,mpp,v);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        int size=connections.size();

        unordered_map<int , vector<int>>adj;

        for(int i=0;i<size;i++)
        {
            int u=connections[i][0];

            int v=connections[i][1];

            adj[u].push_back(v);

            adj[v].push_back(u);
        }

        map<int , int>mp;

        map<int , set<int>>mpp;

        int id=0;

        vector<int>vis(c+1,false);

        for(int i=1;i<=c;i++)
        {
            if(!vis[i])
              dfs(id,adj,vis,mp,mpp,i);

            id++;
        }

        vector<int>offline(c+1,false);

        vector<int>ans;

        for(int i=0;i<queries.size();i++)
        {
            int op=queries[i][0];

            int node=queries[i][1];

            if(op==2)
            {
               offline[node]=true;
               mpp[mp[node]].erase(node);
               continue;
            }

            if(offline[node]==false)
              ans.push_back(node);
            else if(mpp[mp[node]].size()>0)
            {
                ans.push_back(*mpp[mp[node]].begin());
            }
            else
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};