class Solution {
public:
    int smallestNumber(int n) {

        int bitmask=0;

        int idx=1;

        for(int i=0;i<32;i++)
        {
            if((n & (1<<i))!=0)
            {
                idx=i;
            }
        }

        int m=n;
        
        for(int i=0;i<idx;i++)
        {
            if((n & (1<<i))==0)
            {
                m= (m | (1<<i));
            }
        }

        return m;

        
    }
};