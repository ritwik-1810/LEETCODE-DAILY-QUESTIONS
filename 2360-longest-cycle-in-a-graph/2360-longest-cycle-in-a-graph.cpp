class Solution {
public:
    void DFS(vector<int>& edges,vector<bool>&inRecur,vector<bool>&vis,vector<int>&count,int &maxi,int i)
    {
        vis[i]=true;

        inRecur[i]=true;

        int v = edges[i];
        
        if(v!=-1 && !vis[v])
        {
            count[v]+=count[i];
            DFS(edges,inRecur,vis,count,maxi,v);
        }
        else if(v!=-1 && inRecur[v])
        {
            maxi = max(maxi,count[i]-count[v]+1);
            return;
        }
        

        inRecur[i] = false;

    }
    int longestCycle(vector<int>& edges) {

        int size = edges.size();

        vector<bool>inRecur(size);

        vector<bool>vis(size);


        int maxi=-1;

        vector<int>count(size,1);

        for(int i=0;i<size;i++)
        {
            

            int max1=0;

            DFS(edges,inRecur,vis,count,max1,i);

            if(max1>0) maxi=max(maxi,max1);
 
        }

        return maxi;

    }
};