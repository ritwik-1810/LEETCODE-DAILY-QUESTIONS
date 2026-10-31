class Solution {
public:
    void dfs(string from,string to,unordered_map<string,bool>&vis,unordered_map<string,vector<pair<string,double>>>&adjList,double totVal,double &sol)
    {
        if(from == to)
        {
           sol=totVal;
           return;
        }
        
        vis[from]=true;

        for(auto [key,val]:adjList[from])
        {
            if(!vis[key])
            {
                totVal*=val;
                dfs(key,to,vis,adjList,totVal,sol);
                totVal/=val;
            }
        }

        return;
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

            double sol=-1.0;
                
            if(!adjList.count(from) || !adjList.count(to))
            {
              ans.push_back(-1.0);
              continue;
            }
           
              unordered_map<string,bool>vis;
              double totVal=1.0;
              dfs(from,to,vis,adjList,totVal,sol);
              ans.push_back(sol);
            
        }

        return ans;
    }
};