class Solution {
public:
    int MOD=1e9 + 7;
    int solve(int low,int high,int zero,int one,int cons,vector<int>&t)
    {
         if(cons>high) return 0;

         if(t[cons]!=-1) return t[cons];

         int left=0;

         int right=0;

         bool addOne=false;

         if(cons>=low && cons<=high)
         addOne=true;

         left = solve(low,high,zero,one,cons+zero,t);

         right = solve(low,high,zero,one,cons+one,t);
        
         if(addOne) return t[cons]=(1 + left + right)%MOD;

         return t[cons]=(left+right)%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {

        vector<int>t(high+1,-1);

        return solve(low,high,zero,one,0,t);

    }
};