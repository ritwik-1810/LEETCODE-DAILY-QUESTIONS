class Solution {
public:
    int MOD=1000000007;
    int solve(long long a,long long b)
    {
        if(b==0)
        {
            return 1;
        }
        
        long long half = solve(a,b/2);

        long long result = (half*half)%MOD;

        if(b%2==1) 
         result=(a*result)%MOD;

         return result;
    }
    int countGoodNumbers(long long n) {
        // Your code goes here

        long long even=(n+1)/2;

        long long odd=n/2;

        return (1LL*solve(5,even)*solve(4,odd))%MOD;


    }
};
