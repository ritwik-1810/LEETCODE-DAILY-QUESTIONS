class Solution {
public:
    int numberOfSubstrings(string s) {

        int size=s.size();

        vector<int>cumCnt(size,0);

        cumCnt[0]=((s[0]=='1') ? 1 : 0);

        for(int i=1;i<size;i++)
        {
            cumCnt[i]=cumCnt[i-1] + ((s[i]=='1') ? 1 : 0);
        }

        int res=0;

        for(int i=0;i<size;i++)
        {
            for(int j=i;j<size;j++)
            {
                 int cnt1=cumCnt[j] - ((i-1>=0) ? cumCnt[i-1] : 0);

                 int cnt0=( j - i + 1) - cnt1;

                 if((cnt0 * cnt0) > cnt1)
                 {
                      int waste =((cnt0 * cnt0)-cnt1); 

                      j+=waste-1;
                 }
                 else if((cnt0 * cnt0) == cnt1)
                 {
                     res+=1;
                 }
                 else
                 {
                     res+=1;

                     int k = sqrt(cnt1) - cnt0;

                     int next = j + k;

                     if(next>=size)
                     {
                         res+=(size-j-1);
                         break;
                     } 
                     
                     res+=k;

                     j=next;
                     
                 }
            }
        }

        return res;
        
    }
};