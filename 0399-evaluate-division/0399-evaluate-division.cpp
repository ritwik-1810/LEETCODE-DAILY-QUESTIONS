class Solution {
public:
    bool dfs(string from,string to,unordered_map<string,bool>&vis,unordered_map<string,vector<pair<string,double>>>&adjList,double &totVal)
    {
        if(from == to)
          return true;
        
        vis[from]=true;

        for(auto [key,val]:adjList[from])
        {
            if(!vis[key])
            {
                if(dfs(key,to,vis,adjList,totVal))
                {
                    totVal*=val;
                    return true;
                }
            }
        }

        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int size = values.size();
           
        vector<double>ans;

        unordered_map<string,vector<pair<string,double>>>adjList;

        for(int i=0;i<size;i++)
        {
           string key1 = equations[i][0];
           string key2=equations[i][1];
           double val=values[i];
           adjList[key1].push_back({key2,val});
           adjList[key2].push_back({key1,1.0/val});
        }

        int querSize=queries.size();

        for(int i=0;i<querSize;i++)
        {
            string from=queries[i][0];
            string to=queries[i][1];
                
            if(!adjList.count(from) || !adjList.count(to))
{
    ans.push_back(-1.0);
    continue;
}
           
                unordered_map<string,bool>vis;
                double totVal=1.0;
                bool dfsCall=dfs(from,to,vis,adjList,totVal);
                if(dfsCall)
                ans.push_back(totVal);
                else
                ans.push_back(-1*1.0);
            
        }

        return ans;
    }
};