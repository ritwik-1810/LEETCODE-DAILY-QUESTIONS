class Solution {
public:
    int countPalindromicSubsequence(string s) {

          int n=s.size();

          int result=0;
          
          unordered_set<char>st;

          for(auto str:s)
          {
              st.insert(str);
          }

          for(auto sr:st)
          {
              int start=-1;
              int end=-1;

              for(int i=0;i<n;i++)
              {
                  if(s[i]==sr)
                  {
                      if(start==-1)
                      {
                         start=i;
                      }

                      end=i;

                  }
              }

              unordered_set<char>ust;

              for(int i=start+1;i<=end-1;i++)
              {
                  ust.insert(s[i]);
              }

              result+=ust.size();
          }

        return result;
    }
};