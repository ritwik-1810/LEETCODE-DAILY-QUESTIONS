class Solution {
public:
    int smallestRepunitDivByK(int k) {

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