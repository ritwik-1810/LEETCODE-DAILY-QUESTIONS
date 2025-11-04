class Solution {
public:
    int t[50];
    int solve(int n)
    {
        if(n==0)
         return 1;

        if(t[n]!=-1)
          return t[n];

        int ans=0;
        
        if(n-2>=0)
          
          ans+=solve(n-2);

        if(n-1>=0)
          
          ans+=solve(n-1);

        return t[n] = ans;
        
    }
    int climbStairs(int n) {

        memset(t,-1,sizeof(t));

        return solve(n);
        
    }
};