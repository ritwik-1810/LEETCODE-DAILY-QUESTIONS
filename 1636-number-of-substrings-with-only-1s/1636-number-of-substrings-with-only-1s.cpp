class Solution {
public:
    int MOD=1e9+7;
    int numSub(string s) {

        int size=s.size();

        int i=0;

        int j=0;

        int res=0;

        while(i<size)
        {
              if(s[i]=='0')
              {
                 i++;
                 j++;
              }
              else
              {
                  while(s[j]=='1')
                  {
                      j++;
                  }

                  int val=j-i;

                  long long sunst=((long long)val * (val+1)) /2;
                 
                  res=(res+sunst)%MOD;
 
                  i=j;

              }
        }

        return res;
        
    }
};