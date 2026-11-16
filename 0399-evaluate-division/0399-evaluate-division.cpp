class Solution {
public:
    bool dfs(string from,string to,unordered_map<string,vector<pair<string,double>>>&adjedencyList,double &cal,double val,unordered_set<string>&vis)
    {
        if(!adjedencyList.count(from))
        {
           return false;
        }

        vis.insert(from);

        if(from==to) 
        {   
            cal=val;
            
            return true;
        }
        for(auto [t,v]:adjedencyList[from])
        {
           if(vis.count(t)) continue;


           if(dfs(t,to,adjedencyList,cal,val*v,vis))
           {
               return true;
           }

        }

        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int size = values.size();

        unordered_map<string,vector<pair<string,double>>>adjedencyList;

        vector<double>ans;

        //make graph

        for(int i=0;i<size;i++)
        {
            string u = equations[i][0];

            string v = equations[i][1];

            double val1 = values[i];

            double val2 = 1/values[i];

            adjedencyList[u].push_back({v,val1});

            adjedencyList[v].push_back({u,val2});

        }

        //traverse queries and calculate answer using adj list-->

        int queriesSize=queries.size();
        
        for(int i=0;i<queriesSize;i++)
        {
            string from = queries[i][0];

            string to = queries[i][1];

            double cal = -1.0;

            unordered_set<string>vis;

            if(dfs(from,to,adjedencyList,cal,1.0,vis))
            {
                ans.push_back(cal);
            } 
            else
            {
                ans.push_back(-1.0);
            }
        }

         return ans;
        
    }
};