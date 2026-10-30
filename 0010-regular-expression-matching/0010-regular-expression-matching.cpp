class Solution {
public:
    bool solve(string &s,string &p,int i,int j,vector<vector<int>>&dp)
    {
         if(j>=p.size()) return i>=s.size();

         if(dp[i][j]!=-1) return dp[i][j];

         bool take=false;

         bool nottake=false;

         if((j+1<p.size() && p[j+1]=='*'))
         {
             

             if(i<s.size() && (p[j]=='.' || p[j]==s[i]))
             {
             take=solve(s,p,i+1,j,dp);
             }

             nottake=solve(s,p,i,j+2,dp);
             
         }
         else if(i<s.size() && (s[i]==p[j] || p[j]=='.'))
           return dp[i][j]=solve(s,p,i+1,j+1,dp);
         else return dp[i][j]=false;

         
         return dp[i][j]=take || nottake;
    }
    bool isMatch(string s, string p) {



        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));

        return solve(s,p,0,0,dp);
        
    }
};