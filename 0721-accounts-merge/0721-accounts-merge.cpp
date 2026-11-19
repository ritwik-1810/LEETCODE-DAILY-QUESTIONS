class Solution {
public:
     int findParent(int x,vector<int>&parent)
    {
        if(parent[x]==x) return x;

        return parent[x] = findParent(parent[x],parent);
    }
    void union1(int x,int y,vector<int>&parent,vector<int>&rank)
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

        return;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

         int size = accounts.size();

        vector<int>parent(size);

        vector<int>rank(size,0);

        for(int i=0;i<size;i++)
        {
            parent[i]=i;
        }

        //step - 1 email -> i making DSU common email will have same parent

        unordered_map<string,int>emails;  



        for(int i=0;i<size;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string email=accounts[i][j];

                if(!emails.count(email))
                {
                    emails[email]=i;
                }
                else
                {
                    union1(i,emails[email],parent,rank);
                }
            }
        }

        //step - 2 Parent index -> vector<email> using email map and parent vector

        unordered_map<int,vector<string>>groups;

        for(auto &g:emails)
        {
            int parentIdx = findParent(g.second,parent);

            groups[parentIdx].push_back(g.first);
        }

        //step - 3 final answer 

        vector<vector<string>>results;

        for(auto [idx,e]:groups)
        {
            sort(e.begin(),e.end());

            string name = accounts[idx][0];

            vector<string>temp;

            temp.push_back(name);

            for(auto str:e)
            {
                temp.push_back(str);
            }

            results.push_back(temp);
        }
        
        return results;
        
    }
};