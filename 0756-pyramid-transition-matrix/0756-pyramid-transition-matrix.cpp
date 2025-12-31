class Solution {
public:
    unordered_map<string , bool>dp;

    bool solve(string curr , int i , unordered_map<string,vector<char>>&mp,string upper)
    {
         if(curr.size()==1)
         {
            return true;
         }

          string key=curr + '|' + to_string(i) + '|' + upper;

         if(dp.count(key)) return dp[key];

         if(i==curr.size()-1)
         {
            return dp[key]=solve(upper,0,mp,"");
         }

         string s=curr.substr(i,2);

         if(!mp.count(s)) return dp[key]=false;

         for(auto ch:mp[s])
         {
             upper.push_back(ch); // do

             if(solve(curr,i+1,mp,upper)) return dp[key]=true; //explore

             upper.pop_back(); // backtrack
         }

         return dp[key] = false;
         
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        unordered_map<string,vector<char>>mp;

        int size = allowed.size();

        for(int i=0;i<size;i++)
        {
            string s = allowed[i].substr(0,2);

            mp[s].push_back(allowed[i][2]);
        }

        return solve(bottom,0,mp,"");
        
    }
};