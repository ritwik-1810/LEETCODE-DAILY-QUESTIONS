class Solution {
public:
    int f(int n)
    {
        if(n==1 || n==0) return 1;

        if(n==2) return 2;

        int ans=0;
        
         for(int i=1;i<=n;i++)
         {
            ans+=f(i-1) * f(n-i);
         }

         return ans;
        
    }
    int numTrees(int n) {

         return f(n);
    }
};