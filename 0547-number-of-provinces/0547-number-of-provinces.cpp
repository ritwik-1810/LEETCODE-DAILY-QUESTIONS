class Solution {
public:
    int findParent(int x,vector<int>&parent)
    {
        if(parent[x]==x) return x;

        return parent[x] = findParent(parent[x],parent);
    }

    void union1(int x,int y,int &component,vector<int>&parent,vector<int>&rank)
    {
        int parent_x = findParent(x,parent);

        int parent_y = findParent(y,parent);

        if(parent_x == parent_y)
          return;

         if(rank[parent_x] < rank[parent_y])
        {
            parent[parent_x] = parent_y;
        }
        else if(rank[parent_x] > rank[parent_y])
        {
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_x] == rank[parent_y])
        {
            parent[parent_y] = parent_x;

            rank[parent_x]+=1;
        }

        component-=1;

        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int size = isConnected.size();

        vector<int>parent(size);

        vector<int>rank(size,0);

        for(int i=0;i<size;i++)
        {
            parent[i]=i;
        }

        int component=size;
        
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(isConnected[i][j]==1)
                {
                    union1(i,j,component,parent,rank);
                }
            }
        }


        return component;
 
    }
};