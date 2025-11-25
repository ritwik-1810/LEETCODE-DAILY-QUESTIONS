class Solution {
public:
    int smallestRepunitDivByK(int k) {


        //note 

        /*

        first we try to build the brute force approach then it does not work so we 

        optimize a bit because n may not fit in a 64-bit signed integer. 

        so we use remainder.. by doing %k;


        */

        long long n=1;

        if(k%10!=1 && k%10!=3 && k%10!=7 && k%10!=9)
          return -1;

        int len=1;

        while(true)
        {
            if(n%k==0) return len;

            n=(n*10+1)%k;

            len++;
        }

        return -1;
        
    }
};