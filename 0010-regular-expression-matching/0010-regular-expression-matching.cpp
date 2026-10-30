class Solution {
public:
    bool solve(string &s,string &p,int i,int j)
    {
         if(j>=p.size()) return i>=s.size();

         bool take=false;

         bool nottake=false;

         if((j+1<p.size() && p[j+1]=='*'))
         {
             nottake=solve(s,p,i,j+2);

             if(i<s.size() && (p[j]=='.' || p[j]==s[i]))
             {
             take=solve(s,p,i+1,j);
             }
             
         }
         else if(i<s.size() && (s[i]==p[j] || p[j]=='.'))
           return solve(s,p,i+1,j+1);
         else return false;

         
         return take || nottake;
    }
    bool isMatch(string s, string p) {

        return solve(s,p,0,0);
        
    }
};