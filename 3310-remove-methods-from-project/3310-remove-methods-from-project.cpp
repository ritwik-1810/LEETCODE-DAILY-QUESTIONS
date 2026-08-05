class Solution {
public:
    void dfs( unordered_map<int,vector<int>>&undirected,int k, vector<int>&vis)
    {
        vis[k]=1;

        for(auto it:undirected[k])
        {
            if(vis[it]==-1)
            {
                dfs(undirected,it,vis);
            }
        }
    }
    void dfs1( unordered_map<int,vector<int>>&directed,int k, vector<bool>&vis1)
    {
        vis1[k]=true;

        for(auto it:directed[k])
        {
            if(vis1[it]==false)
            {
                dfs1(directed,it,vis1);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        int size = invocations.size();

        unordered_map<int,vector<int>>directed;

        unordered_map<int,vector<int>>undirected;

        for(int i=0;i<size;i++)
        {
           int u = invocations[i][0];

           int v = invocations[i][1];

           directed[u].push_back(v);

           undirected[u].push_back(v);

           undirected[v].push_back(u);
        }

        vector<int>vis(n,-1);

        
        dfs(undirected,k,vis);
        

        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
             ans.push_back(i);
        }

        vector<bool>vis1(n,false);

        dfs1(directed,k,vis1);

        bool isTrue=false;

        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1) continue;

            if(vis1[i]==false)
             isTrue=true;
        }

        if(isTrue==false) return ans;
        
         for(int i=0;i<n;i++)
        {
            if(vis[i]==-1) continue;

            ans.push_back(i);
        }

       return ans;
    }
};