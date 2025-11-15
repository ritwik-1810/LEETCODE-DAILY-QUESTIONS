class Solution {
public:
    int count(int i,int j,string s)
    {
          int cnt=0;

          while(i>=0 && j<s.size() && s[i]=='1' && s[j]=='0')
          {
              cnt+=1;

              i--;

              j++;
          }

          return cnt;
    }
    int count1(int i,int j,string s)
    {
          int cnt=0;

          while(i>=0 && j<s.size() && s[i]=='0' && s[j]=='1')
          {
              cnt+=1;

              i--;

              j++;
          }

          return cnt;
    }
    int countBinarySubstrings(string s) {

        int size=s.size();

        int res=0;

        for(int i=0;i<size-1;i++)
        {
             if(s[i]=='1' && s[i+1]=='0')
             {
                  res+=count(i,i+1,s);
             }
             else if(s[i]=='0' && s[i+1]=='1')
             {
                  res+=count1(i,i+1,s);
             }
        }

        return res;

    }
};