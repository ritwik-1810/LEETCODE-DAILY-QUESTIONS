class Solution {
public:
    int MOD=1e9+7;
    int countHomogenous(string s) {

        int size=s.size();

        int i=0;

        int j=1;

        int res=0;

        while(i<size)
        {
              
                  while(s[j]==s[j-1])
                  {
                      j++;
                  }

                  int val=j-i;

                  long long sunst=((long long)val * (val+1)) /2;
                 
                  res=(res+sunst)%MOD;
 
                  i=j;

                  j++;
              
        }

        return res;

    }
};