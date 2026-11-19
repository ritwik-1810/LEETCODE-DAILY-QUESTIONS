class Solution {
public:
    int findDiameter(unordered_map<int,vector<int>>&adj,int size)
    {
        //step--1 find the farthest node from any node say 0 to get one end of diameter

        queue<int>q;  // node
        
        vector<bool>vis(size,false);

        int lastNode=0;

        vis[0]=true;

        q.push(0);

        while(!q.empty())
        {
            int s = q.size();

            while(s--)
            {
                lastNode=q.front();

                q.pop();

                for(auto &v:adj[lastNode])
                {
                   if(!vis[v])
                   {
                      q.push(v);
                      vis[v]=true;
                   }
                }

            }
        }

        // Step 2 find farthest distance form lastNode 
        
        queue<int>q1;  // node
        
        vector<bool>vis1(size,false);

        int diameter=0;

        vis1[lastNode]=true;

        q1.push(lastNode);

        while(!q1.empty())
        {
            int s = q1.size();

            while(s--)
            {
                int u=q1.front();

                q1.pop();

                for(auto &v:adj[u])
                {
                   if(!vis1[v])
                   {
                      q1.push(v);
                      vis1[v]=true;
                   }
                }

            }

            if(!q1.empty()) diameter+=1;
        }

        return diameter;
        
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        int size1 = edges1.size();

        int size2 = edges2.size();
        
        unordered_map<int,vector<int>>adj;

        unordered_map<int,vector<int>>adj2;

        for(int i=0;i<size1;i++)
        {
            int u = edges1[i][0];
            int v = edges1[i][1];

            adj[u].push_back(v);

            adj[v].push_back(u);
        }

        for(int i=0;i<size2;i++)
        {
            int u = edges2[i][0];
            int v = edges2[i][1];

            adj2[u].push_back(v);

            adj2[v].push_back(u);
        }

        int diameter1 = findDiameter(adj,size1+1);

        int diameter2 = findDiameter(adj2,size2+1);

        return max({
    diameter1,
    diameter2,
    (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1
}); 

    }
};