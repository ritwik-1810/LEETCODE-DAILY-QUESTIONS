class Solution {
public:
    char processStr(string s, long long k) {

        int size = s.size();

        long long L=0;

        for(int i=0;i<size;i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                L++;
            }
            else if(s[i]=='#')
            {
                L+=L;
            }
            else if(s[i]=='*')
            {
                if(L>0)
                L--;
            }

        }

        if(k>=L) return '.';

        for(int i=size-1;i>=0;i--)
        {
            if(s[i]=='*')
            {
                L++;
            }
            else if(s[i]=='%')
            {
                k=abs(k-(L-1));
            }
            else if(s[i]=='#')
            {
                L=L/2;
                
                if(k>=L)
                k=(k-L);
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                L--;

                 if(k==L)
                   return s[i];
            }

           
        }

        return '.';
        
    }
};